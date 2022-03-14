#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> acc;
public:
    Solution(vector<int>& w) {
        acc.resize(w.size(), 0);
        int sum = 0;
        for (int i = 0; i < w.size(); ++i) {
            sum += w[i];
            acc[i] = sum;
        }
    }
    
    int pickIndex() {
        int rad = rand() % acc.back() + 1;
        int left = 0;
        int right = acc.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (rad <= acc[mid]) {
                if (mid == 0 || rad > acc[mid - 1]) return mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */