#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.size();
        for (int i = 0; i < 2*n-1; i++) {
            int l = i/2, r = i/2+i%2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                res++;
            }
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

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().countSubstrings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}