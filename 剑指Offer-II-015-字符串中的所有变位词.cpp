#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n1 = s.length();
        int n2 = p.length();
        if (n1 < n2) return res;

        vector<int> cnt(26);
        for (int i = 0; i < n2; i++) {
            cnt[s[i]-'a'] += 1;
            cnt[p[i]-'a'] -= 1;
        }

        int diff = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) diff++;
        }
        if (diff == 0) res.push_back(0);

        for (int i = n2; i < n1; i++) {
            int out = s[i-n2]-'a', in = s[i]-'a';
            if (cnt[out] == 0) diff++;
            cnt[out] -= 1;
            if (cnt[out] == 0) diff--;

            if (cnt[in] == 0) diff++;
            cnt[in] += 1;
            if (cnt[in] == 0) diff--;

            if (diff == 0) res.push_back(i-n2+1);
        }

        return res;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        vector<int> ret = Solution().findAnagrams(s, p);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}