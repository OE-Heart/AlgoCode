#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int calArea(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        vector<pair<int, int>> stack;
        stack.push_back({i, j});
        visited[i][j] = true;
        
        int area = 0;
        pair<int, int> back;
        int r, c;
        while (stack.size() > 0) {
            back = stack.back();
            stack.pop_back();
            area++;
            for (auto& d: dir) {
                r = back.first + d.first;
                c = back.second + d.second;
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1 && !visited[r][c]) {
                    stack.push_back({r, c});
                    visited[r][c] = true;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int res = 0;
        int area;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    area = calArea(i, j, grid, visited);
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};