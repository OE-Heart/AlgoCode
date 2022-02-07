#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> mp;
        long bucketSize = static_cast<long>(t) + 1;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int ID = getBucketID(num, bucketSize);
            if (mp.count(ID) 
            || (mp.count(ID - 1) &&  min(INT_MAX - t, mp[ID - 1]) + t >= num)
            || (mp.count(ID + 1) &&  max(INT_MIN + t, mp[ID + 1]) - t <= num)) {
                return true;
            }
            mp[ID] = num;
            if (i >= k) {
                mp.erase(getBucketID(nums[i - k], bucketSize));
            }
        }
        return false;
    }

private:
    int getBucketID(int n, long size) {
        return (n >= 0) ? n / size : (n + 1) / size - 1;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        getline(cin, line);
        int t = stringToInteger(line);
        
        bool ret = Solution().containsNearbyAlmostDuplicate(nums, k, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}