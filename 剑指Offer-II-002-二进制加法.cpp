#include <iostream>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aa = 0, bb = 0;
        for (int i = 0; i < a.size(); i++) {
            aa *= 2;
            aa += (a.at(i) == '1') ? 1 : 0;
        }
        std::cout << aa << std::endl;
        for (int i = 0; i < b.length(); i++) {
            bb *= 2;
            bb += (b.at(i) == '1') ? 1 : 0;
        }
        std::cout << bb << std::endl;
        int c = aa+bb;
        string res;
        while (c >= 2) {
            res.push_back(c%2 ? '1' : '0');
            c /= 2;
        }
        res.push_back(c ? '1' : '0');
        reverse(res.begin(), res.end());
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);
        
        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}