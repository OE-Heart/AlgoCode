#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Trie {
public:
    vector<Trie*> children;
    bool isEnd;

    Trie() : children(26), isEnd(false) {}
    
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (node->children[ch - 'a'] == NULL) node->children[ch - 'a'] = new Trie();
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }
};

class MagicDictionary {
private:
    Trie* root;
    bool dfs(Trie* root, string& word, int i, int edit) {
        if (root == nullptr) return false;

        if (root->isEnd && i == word.size() && edit == 1) return true;

        if (i < word.size() && edit <= 1) {
            bool found = false;
            for (int j = 0; j < 26; ++j) {
                found = dfs(root->children[j], word, i + 1, (j == word[i] - 'a') ? edit : edit + 1);
                if (found) return true;
            }
        }

        return false;
    }

public:
    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for (string word : dictionary) {
            root->insert(word);
        }
    }
    
    bool search(string searchWord) {
        return dfs(root, searchWord, 0, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */