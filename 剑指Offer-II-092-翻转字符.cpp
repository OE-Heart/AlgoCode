#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp[2] = {0, 0};
        int t[2];
        for (int i = 0; i < s.length(); ++i) {
            t[0] = dp[0] + (int)(s[i] != '0');
            t[1] = min(dp[0], dp[1]) + (int)(s[i] != '1');
            dp[0] = t[0];
            dp[1] = t[1];
        }
        return min(dp[0], dp[1]);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int ret = Solution().minFlipsMonoIncr(line);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}