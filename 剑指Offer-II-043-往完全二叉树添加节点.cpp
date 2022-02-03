#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> Q;
    TreeNode* front;
    CBTInserter(TreeNode* root) {
        this->root = root;
        Q.push(root);
        front = Q.front();
        while (front->left != NULL && front->right != NULL) {
            Q.push(front->left);
            Q.push(front->right);
            Q.pop();
            front = Q.front();
        }

        if (front->left != NULL) Q.push(front->left);
        if (front->right != NULL) Q.push(front->right);
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        Q.push(node);
        if (front->left == NULL) {
            front->left = node;
        }
        else if (front->right == NULL) {
            front->right = node;
        }
        else {
            Q.pop();
            front = Q.front();
            front->left = node;
        }
        return front->val;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */