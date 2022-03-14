#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0)-nums[0];
        // cout << "left=" << left << ", right=" << right << endl;
        if (left == right) return 0;
        for (int i = 1; i < n; i++) {
            left += nums[i-1];
            right -= nums[i];
            // cout << "left=" << left << ", right=" << right << endl;
            if (left == right) {
                res = i;
                break;
            }
        }

        return res;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().pivotIndex(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}