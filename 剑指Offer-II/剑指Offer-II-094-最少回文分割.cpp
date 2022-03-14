#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        int cenL = 0;
        int cenR = 0;
        while (cenR < n) {
            int left = cenL;
            int right = cenR;
            while (left >= 0 && right < n && s[left] == s[right]) {
                isPalindrome[left--][right++] = true;
            }
            cenR > cenL ? cenL++ : cenR++;
        }

        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            if (isPalindrome[0][i]) dp[i] = 0;
            else {
                dp[i] = i;
                for (int j = 1; j <= i; ++j) {
                    if (isPalindrome[j][i]) dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        
        return dp[n - 1];
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
        
        int ret = Solution().minCut(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}