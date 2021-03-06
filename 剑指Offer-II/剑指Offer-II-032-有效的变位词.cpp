#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if (n != t.length()) return false;
        int i ;
        for (i = 0; i < n ; i++) {
            if (s[i] != t[i]) break;
        }
        if (i == n) return false;

        vector<int> hashTable(26);
        for (int i = 0; i < s.length(); i++) {
            hashTable[s[i]-'a'] += 1;
        }
        for (int i = 0; i < t.length(); i++) {
            hashTable[t[i]-'a'] -= 1;
        }
        for (int i = 0; i < 26; i++) {
            if (hashTable[i] != 0) return false;
        }

        return true;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);
        
        bool ret = Solution().isAnagram(s, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}