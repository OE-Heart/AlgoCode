#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string lock = "0000";
        if (target == lock) return 0;

        unordered_set<string> dead;
        for (auto& s: deadends) {
            dead.insert(s);
        }

        if (dead.count(lock)) return -1;

        unordered_set<string> st1;
        unordered_set<string> st2;
        st1.insert(lock);
        st2.insert(target);

        int len = 0;
        while (!st1.empty() && !st2.empty()) {
            if (st1.size() > st2.size()) swap(st1, st2);

            unordered_set<string> st3;
            len++;
            for (string s: st1) {
                dead.insert(s);
                if (getNeighbor(dead, st1, st2, st3, s)) return len;
            }
            st1 = st3;
        }
        return -1;
    }

    bool getNeighbor(unordered_set<string>& dead, unordered_set<string>& st1, unordered_set<string>& st2, unordered_set<string>& st3, string& lock) {
        for (int i = 0; i < lock.length(); ++i) {
            char temp = lock[i];
            string var(2,' ');
            var[0] = (temp + 1 > '9') ? '0': temp + 1;
            var[1] = (temp - 1 < '0') ? '9': temp - 1;

            for (auto& ch: var) {
                lock[i] = ch;
                if (!dead.count(lock)) {
                    if (st2.count(lock)) return true;
                    st3.insert(lock);
                }
            }
            lock[i] = temp;
        }
        return false;
    }
};