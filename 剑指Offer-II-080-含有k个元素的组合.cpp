#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(res, cur, 1, n, k);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& cur, int i, int n, int k) {
        if (cur.size() == k) {
            res.push_back(cur);
            return ;
        }
        if (i > n) return ;
        cur.push_back(i);
        backtrack(res, cur, i + 1, n, k);
        cur.pop_back();
        backtrack(res, cur, i + 1, n, k);
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> res = Solution().combine(n, k);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < k; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}