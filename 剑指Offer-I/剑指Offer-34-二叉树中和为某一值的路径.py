class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, ret, cur, node: TreeNode, target: int):
        cur.append(node.val)
        target -= node.val
        if target == 0 and not node.left and not node.right:
            ret.append(cur.copy())
        else:
            if node.left: self.dfs(ret, cur, node.left, target)
            if node.right: self.dfs(ret, cur, node.right, target)
        target += node.val
        cur.pop()


    def pathSum(self, root: TreeNode, target: int):
        ret = []
        cur = []
        if root: self.dfs(ret, cur, root, target)
        return ret