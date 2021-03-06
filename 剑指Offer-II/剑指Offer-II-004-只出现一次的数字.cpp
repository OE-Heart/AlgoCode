#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int b = 0;
        for (int i = 31; i >= 0; i--) {
            int sum = 0;
            for (int num: nums) {
                sum += (num>>i)&0b1;
            }
            b = (b<<1)+sum%3;
        }
        return b;
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
        
        int ret = Solution().singleNumber(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}