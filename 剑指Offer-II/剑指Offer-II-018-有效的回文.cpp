#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        bool res = true;
        int n = s.length();
        int i = 0, j = n-1;
        while (i < j) {
            char a = (char)s[i], b = (char)s[j];
            while (i < j && !isValidChar(a)) a = (char)s[++i];
            while (i < j && !isValidChar(b)) b = (char)s[--j];
            if (i >= j) break;
            
            if (!isEqualChar(a, b)) {
                res = false;
                break;
            }
            i++;
            j--;
        }

        return res;
    }

    bool isValidChar(char c) {
        if (c >= 'a' && c <= 'z') return true;
        else if (c >= 'A' && c <= 'Z') return true;
        else if (c >= '0' && c <= '9') return true;
        else return false;
    }

    bool isEqualChar(char a, char b) {
        if (a == b) return true;
        else if (a >= 'a' && a <= 'z' && a-32 == b) return true;
        else if (a >= 'A' && a <= 'Z' && a+32 == b) return true;
        else return false;
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
        
        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}