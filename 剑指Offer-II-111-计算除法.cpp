#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
private:
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visted, string start, string end, double val) {
        if (start == end) return val;

        visted.insert(start);      
        for (auto& node : graph[start]) {
            if (!visted.count(node.first)) {
                double ret = dfs(graph, visted, node.first, end, node.second * val);
                if (ret > 0) return ret;
            }
        }
        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> ret(queries.size(), -1.0);
        for (int i = 0; i < queries.size(); ++i) {
            if (graph.count(queries[i][0]) && graph.count(queries[i][1])) {
                unordered_set<string> visted;
                ret[i] = dfs(graph, visted, queries[i][0], queries[i][1], 1);
            }
        }
        return ret;
    }
};