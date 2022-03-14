#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Trie {
public:
    int val;
    vector<Trie*> children;
    Trie () : val(0), children(26, NULL) {}

    void insert(string& str, int m) {
        Trie* node = this;
        for (char ch : str) {
            if (node->children[ch - 'a'] == NULL) node->children[ch - 'a'] = new Trie();
            node = node->children[ch - 'a'];
        }
        node->val = m;
    }

    int getSum(string &prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (node->children[ch - 'a'] == NULL) return 0;
            node = node->children[ch - 'a'];
        }

        int count = 0;
        queue<Trie*> que;
        que.push(node);
        while (!que.empty()) {
            Trie* node = que.front();
            que.pop();
            count += node->val;
            for (int i = 0; i < node->children.size(); ++i) {
                if (node->children[i] != NULL) que.push(node->children[i]);
            }
        }
        return count;
    }
};

class MapSum {
private:
    Trie* root;
public:
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        root->insert(key, val);
    }
    
    int sum(string prefix) {
        return root->getSum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */