#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] == -nums[i]) {
                    res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if (nums[j] + nums[k] > -nums[i]) k--;
                else j++;
            }
            
        }
        return res;
    }
};