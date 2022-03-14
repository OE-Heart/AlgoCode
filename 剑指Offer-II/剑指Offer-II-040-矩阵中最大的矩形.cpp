#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].length();
        vector<int> dp(cols);
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') dp[j] += 1;
                else dp[j] = 0;
            }
            res = max(res, largestRectangleArea(dp));
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int res = 0, height;
        vector<int> stack;
        stack.push_back(-1);
        for (int i = 0; i < heights.size(); i++) {
            while (stack.size() > 1 && heights[stack.back()] > heights[i]) {
                height = heights[stack.back()];
                stack.pop_back();
                res = max(res, height*(i-stack.back()-1));
            }
            stack.push_back(i);
        }
        return res;
    }
};