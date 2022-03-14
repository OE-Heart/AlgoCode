#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;
        nextNode(0, graph, path, res);
        return res;
    }


    void nextNode(int cur, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res) {
        path.push_back(cur);
        if (cur  == graph.size() - 1) res.push_back(path);

        for (auto& next: graph[cur]) {
            nextNode(next, graph, path, res);
        }
        path.pop_back();
        return ;
    }
};