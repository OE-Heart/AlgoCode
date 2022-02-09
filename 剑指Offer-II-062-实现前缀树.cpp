#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Trie {
public:
    Trie() : children(26), isEnd(false) {}
    
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (node->children[ch - 'a'] == NULL) node->children[ch - 'a'] = new Trie();
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != NULL && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != NULL;
    }
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (node->children[ch - 'a'] == NULL) return NULL;
            node = node->children[ch - 'a'];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */