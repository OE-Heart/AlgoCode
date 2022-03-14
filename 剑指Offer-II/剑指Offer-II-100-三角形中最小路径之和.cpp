#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int res = INT_MAX;
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == 0) dp[j] += triangle[i][j];
                else if (j == i) dp[j] = dp[j - 1] + triangle[i][j];
                else dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
                if (i == n - 1) res = min(res, dp[j]);
            }
        }
        return res;
    }
};