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

    int getPrefixLen(string word) {
        Trie* node = this;
        int len = 0;
        for (char ch : word) {
            if (node->children[ch - 'a'] == NULL) return 0;
            node = node->children[ch - 'a'];
            len++;
            if (node->isEnd) return len;
        }
        return 0;
    }

private:
    vector<Trie*> children;
    bool isEnd;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        for (string prefix: dictionary) {
            trie->insert(prefix);
        }
        string word = "";
        string res = "";
        int prefixLen;
        char ch;
        for (int i = 0; i < sentence.length(); ++i) {
            ch = (char)sentence[i];
            if (ch != ' ') word.push_back(ch);
            if (ch == ' ' || i == sentence.length() - 1) {
                prefixLen = trie->getPrefixLen(word);
                if (prefixLen == 0) res = res + word + " ";
                else res = res + word.substr(0, prefixLen) + " ";
                word = "";
            }
        }
        res.pop_back();
        return res;
    }
};