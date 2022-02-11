#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Trie {
public:
    vector<Trie*> children;
    Trie () : children(2, NULL) {}

    void insert(int n) {
        Trie* node = this;
        for (int i = 31; i >= 0; --i) {
            int bit = (n >> i) & 1;
            if (node->children[bit] == NULL) node->children[bit] = new Trie();
            node = node->children[bit];
        }
    }

    int maxXOR(int n) {
        Trie* node = this;
        int ret = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (n >> i) & 1;
            if (node->children[!bit] != NULL) {
                ret |= (1 << i);
                node = node->children[!bit];
            }
            else node = node->children[bit];
        }
        return ret;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();
        for (int num : nums) {
            root->insert(num);
        }
        int maxVal = INT_MIN;
        for (int num : nums) {
            int cur = root->maxXOR(num);
            maxVal = max(cur, maxVal);
        }
        return maxVal;
    }
};