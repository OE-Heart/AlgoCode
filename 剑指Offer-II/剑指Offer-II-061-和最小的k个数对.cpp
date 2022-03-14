#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.first+lhs.second < rhs.first+rhs.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        k = min(k, (int)(nums1.size()*nums2.size()));
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
        for (int i = 0; i < min(k, (int)nums1.size()); i++) {
            for (int j = 0; j < min(k, (int)nums2.size()); j++) {
                if (heap.size() < k) heap.push(make_pair(nums1[i], nums2[j]));
                else if (nums1[i]+nums2[j] < heap.top().first+heap.top().second) {
                    heap.pop();
                    heap.push(make_pair(nums1[i], nums2[j]));
                }
            }
        }
        vector<vector<int>> res(k);
        for (int i = k - 1; i >= 0; --i) {
            res[i] = vector<int>({heap.top().first, heap.top().second});
            heap.pop();
        }
        return res;
    }
};