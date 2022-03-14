#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        backtrack(res, cur, s, 0);
        return res;
    }
private:
    void backtrack(vector<vector<string>>& res, vector<string>& cur, string& s, int index) {
        if (index == s.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = index; i < s.size(); ++i) {
            if (isPalindrom(s, index, i)) {
                string str = s.substr(index, i - index + 1);
                cur.push_back(str);
                backtrack(res, cur, s, i + 1);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrom(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};