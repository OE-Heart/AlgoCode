#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> hashTable;
        hashTable[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i] ? 1 : -1;
            if (hashTable.find(sum) != hashTable.end()) {
                int index = hashTable[sum];
                if (i-index > res) res = i-index;
            }
            else hashTable[sum] = i;
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
        
        int ret = Solution().findMaxLength(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}