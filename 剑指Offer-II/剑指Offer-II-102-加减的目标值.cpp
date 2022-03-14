#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) & 1) return 0;
        int n = nums.size();
        int aim = (sum + target) >> 1;
        vector<int> dp(aim + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = aim; j >= 0; --j) {
                if (i != 0 && j - nums[i - 1] >= 0) dp[j] = dp[j] + dp[j - nums[i - 1]];
            }
        }
        return dp[aim];
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().findTargetSumWays(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}