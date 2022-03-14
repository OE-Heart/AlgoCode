#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        bool res = true;
        int n = s.length();
        int i = 0, j = n-1;
        int tag = 0;
        while (i < j) {          
            if (s[i] != s[j]) {
                if (tag) {
                    res = false;
                    break;
                }
                else {
                    tag = 1;
                    int p = i, q = j;
                    while (p < q-1 && s[p] == s[q-1] && s[q] == s[p+1]) {
                        p++;
                        q--;
                    }
                    if (s[p] == s[q-1]) {
                        j--;
                        continue;
                    }
                    else if (s[q] == s[p+1]) {
                        i++;
                        continue;
                    }
                    else {
                        res = false;
                        break;
                    }
                }
            }
            i++;
            j--;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().validPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}