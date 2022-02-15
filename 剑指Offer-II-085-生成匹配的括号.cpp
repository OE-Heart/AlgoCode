#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        int stack = 0;
        backtrack(res, cur, stack, n);
        return res;
    }

    void backtrack(vector<string>& res, string& cur, int stack, int n) {
        if (n == 0) {
            res.push_back(cur);
            for (int i = 0; i < stack; ++i) {
                res.back().push_back(')');
            }
            return ;
        }

        if (stack > 0) {
            cur.push_back(')');
            stack--;
            backtrack(res, cur, stack, n);
            stack++;
            cur.pop_back();
        }

        cur.push_back('(');
        stack++;
        backtrack(res, cur, stack, n - 1);
        stack--;
        cur.pop_back();
    }
};