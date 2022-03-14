#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ret = 0;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        unordered_map<int, int> mp;
        mp[arr[0]] = 0;
        for (int i = 1; i < n; ++i) {
            mp[arr[i]] = i;
            for (int j = 0; j < i; ++j) {
                int temp = arr[i] - arr[j];
                if (mp.count(temp) && mp[temp] < j) dp[i][j] = dp[j][mp[temp]] + 1;
                else dp[i][j] = 2;
                ret = max(ret, dp[i][j]);
            }
        }
        return ret > 2 ? ret : 0;
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
        vector<int> arr = stringToIntegerVector(line);
        
        int ret = Solution().lenLongestFibSubseq(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}