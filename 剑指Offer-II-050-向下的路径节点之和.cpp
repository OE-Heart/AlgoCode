#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        hashTable[0] = 1;
        return preOrder(root, targetSum, 0);
    }

private:
    unordered_map<int, int> hashTable;
    int preOrder(TreeNode* root, int targetSum, int sum) {
        if (root == NULL) return 0;
        sum += root->val;
        int remain = sum-targetSum;
        int count = 0;
        if (hashTable.find(remain) != hashTable.end()) count = hashTable[remain];
        if (hashTable.find(sum) != hashTable.end()) hashTable[sum] += 1;
        else hashTable[sum] = 1;

        count += preOrder(root->left, targetSum, sum);
        count += preOrder(root->right, targetSum, sum);
        hashTable[sum] -= 1;

        return count;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int targetSum = stringToInteger(line);
        
        int ret = Solution().pathSum(root, targetSum);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}