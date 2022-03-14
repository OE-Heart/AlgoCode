#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(res, cur, candidates, target, 0);
        return res;
    }
private:
    void backtrack(vector<vector<int>>& res, vector<int>& cur, vector<int>& candidates, int target, int index) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || index == candidates.size()) return;
        backtrack(res, cur, candidates, target, index + 1);
        cur.push_back(candidates[index]);
        backtrack(res, cur, candidates, target - candidates[index], index);
        cur.pop_back();
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
    int target;
    getline(cin, line);
    vector<int> nums = stringToIntegerVector(line);
    cin >> target;
    vector<vector<int>> res = Solution().combinationSum(nums, target);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}