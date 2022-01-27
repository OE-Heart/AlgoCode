#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> hashTable(26);
        for (int i = 0; i < 26; i++) {
            hashTable[order[i]-'a'] = i;
        }
        int n1, n2;
        for (int i = 0; i < words.size()-1; i++) {
            n1 = words[i].length();
            n2 = words[i+1].length();
            int j;
            for (j = 0; j < n1 && j < n2; j++) {
                if (hashTable[words[i][j]-'a'] < hashTable[words[i+1][j]-'a']) break;
                else if (hashTable[words[i][j]-'a'] == hashTable[words[i+1][j]-'a']) continue;
                else return false;
            }
            if (n1 > n2 && j == n2) return false;
        }

        return true;
    }
};