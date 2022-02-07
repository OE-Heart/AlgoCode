#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        p = root;
    }
    
    int next() {
        while (p != NULL) {
            stack.push_back(p);
            p = p->left;
        }
        p = stack.back();
        stack.pop_back();
        int res = p->val;
        p = p->right;
        return res;
    }
    
    bool hasNext() {
        if (stack.size() > 0) return true;
        if (p != NULL) return true;
        return false;
    }

private:
    vector<TreeNode*> stack;
    TreeNode* p;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */