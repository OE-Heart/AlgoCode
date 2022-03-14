#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<int> stack;
        int back;
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                stack.push_back(i);
                while (stack.size() > 0) {
                    back = stack.back();
                    stack.pop_back();
                    for (auto& v: graph[back]) {
                        if (color[v] == -1) {
                            stack.push_back(v);
                            color[v] = 1 - color[back];
                        }
                        else if (color[v] == color[back]) return false;
                    }
                }
            }
        }
        return true;
    }
};