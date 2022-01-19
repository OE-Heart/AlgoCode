#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        nums.push_back(1);
        int product;
        for (int i = 0, j = 0; i <= j, j < n; i++) {
            if (i == j) product = nums[i];
            else product /= nums[i-1];
            // cout << "product=" << product << endl;
            while (j < n-1 && product * nums[j+1] < k) {
                product *= nums[++j];
                // cout << "Product=" << product << endl;
            }
            if (product < k) res += j-i+1;
            // cout << "res=" << res << endl;
            if (i == j) j++;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().numSubarrayProductLessThanK(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}