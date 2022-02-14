#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        for (int state = 0; state < (1 << n); ++state) {
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) cur.push_back(nums[i]);
            }
            res.push_back(cur);
            cur.clear();
        }
        return res;
    }
};