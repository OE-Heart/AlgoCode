#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
private:
    bool getNeighbor(unordered_set<string>& node, unordered_set<string>& st1, unordered_set<string>& st2, unordered_set<string>& st3, string& word) {
        for (int i = 0; i < word.size(); ++i) {
            char temp = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if (ch != temp && node.count(word)) {
                    if (st2.count(word)) return true;
                    st3.insert(word);
                }
            }
            word[i] = temp;
        }
        return false;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> node;
        for (auto& word : wordList) {
            node.insert(word);
        }
        if (!node.count(endWord)) return 0;

        unordered_set<string> st1;
        unordered_set<string> st2;
        st1.insert(beginWord);
        st2.insert(endWord);
        int len = 2;

        while (!st1.empty() && !st2.empty()) {
            if (st1.size() > st2.size()) swap(st1, st2);
            
            unordered_set<string> st3;
            for (auto it = st1.begin(); it != st1.end(); ++it) {
                string word = *it;
                node.erase(word);

                if (getNeighbor(node, st1, st2, st3, word)) return len;
            }
            st1 = st3;
            len++;
        }

        return 0;
    }
};

//  st1 和 st2 分别存放两个方向上需要访问的节点，每次都选择 st1 和 st2 中数量较小的集合进行搜索，这样可以缩小搜索空间。 st3 保存与当前访问节点相邻的下一步需要访问的节点，在搜索相邻节点的过程中，不断查询访问的节点是否已经在另一个方向搜索的集合里，若已经存在，则代表当前两个搜索方向已经有重合的节点，即已经找到最短路径