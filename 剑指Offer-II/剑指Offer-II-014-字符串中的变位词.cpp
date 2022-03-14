#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        
        vector<int> cnt(26);
        for (int i = 0; i < n1; ++i) {
            --cnt[s1[i] - 'a'];
            ++cnt[s2[i] - 'a'];
        }

        int diff = 0;
        for (int c: cnt) {
            if (c != 0) ++diff;
        }
        if (diff == 0) return true;
        
        for (int i = n1; i < n2; ++i) {
            int x = s2[i] - 'a', y = s2[i - n1] - 'a';
            if (x == y) continue;

            if (cnt[x] == 0) ++diff;
            ++cnt[x];
            if (cnt[x] == 0) --diff;

            if (cnt[y] == 0) ++diff;
            --cnt[y];
            if (cnt[y] == 0) --diff;
            
            if (diff == 0) return true;
        }

        return false;
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
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        
        bool ret = Solution().checkInclusion(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}