#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> que;
        pair<int, int> front;
        int r, c;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (que.size() > 0) {
            front = que.front();
            que.pop();
            for (auto& d: dir) {
                r = front.first + d.first;
                c = front.second + d.second;
                if (r >= 0 && r < m && c >= 0 && c < n) {
                    if (res[r][c] > res[front.first][front.second] + 1) {
                        res[r][c] = res[front.first][front.second] + 1;
                        que.push({r, c});
                    }
                }
            }
        }
        return res;
    }
};