#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        if (s3.length() != n1 + n2) return false;
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1));
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) {
                if (i == 0 && j == 0) dp[0][0] = true;
                else if (i == 0) dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                else if (j == 0) dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                else dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                             || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            }
        }
        return dp[n1][n2];
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
        getline(cin, line);
        string s3 = stringToString(line);
        
        bool ret = Solution().isInterleave(s1, s2, s3);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}