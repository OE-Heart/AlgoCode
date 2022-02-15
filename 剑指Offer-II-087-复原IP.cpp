#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> cur;
        string addr = "";
        backtrack(res, cur, addr, s, 0);
        return res;
    }
private:
    void backtrack(vector<string>& res, vector<string>& cur, string& addr, string& s, int index) {
        if (index == s.size()) {
            if (cur.size() != 4) return ;
            for (int i = 0; i < cur.size(); ++i) {
                if (i != 0) addr.push_back('.');
                addr += cur[i];
            }
            res.push_back(addr);
            addr.clear();
            return ;
        }

        if (cur.size() >= 4) return;

        for (int i = index; i < s.size() && i < index + 3; ++i) {
            if (isValidAddress(s, index, i)) {
                string str = s.substr(index, i - index + 1);
                cur.push_back(str);
                backtrack(res, cur, addr, s, i + 1);
                cur.pop_back();
            }
        }
    }

    bool isValidAddress(string& s, int left, int right) {
        int len = right - left;
        if (len == 2) {
            if (s[left] == '1') return true;
            else if (s[left] == '2') {
                if (s[left + 1]  < '5') return true;
                else if (s[left + 1] == '5' && s[left + 2] <= '5') return true;
            }
        }
        else if (len == 1 && s[left] != '0') return true;
        else if (len == 0)return true;
        return false;
    }
};

int main() {
    string s;
    while (getline(cin, s)) {
        vector<string> res = Solution().restoreIpAddresses(s);
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << endl;
        }
    }
    return 0;
}