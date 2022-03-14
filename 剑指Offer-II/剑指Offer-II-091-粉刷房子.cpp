#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int dp[3] = {costs[0][0], costs[0][1], costs[0][2]};
        int cost[3];
        for (int i = 1; i < costs.size(); ++i) {
            cost[0] = costs[i][0] + min(dp[1], dp[2]);
            cost[1] = costs[i][1] + min(dp[0], dp[2]);
            cost[2] = costs[i][2] + min(dp[0], dp[1]);
            dp[0] = cost[0];
            dp[1] = cost[1];
            dp[2] = cost[2];
        }
        return min(min(dp[0], dp[1]), dp[2]);
    }
};