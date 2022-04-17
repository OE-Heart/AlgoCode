class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder, inorder) -> TreeNode:
        if len(preorder) == 0: return None
        root = TreeNode(preorder[0])
        index = inorder.index(preorder[0])
        if index != 0: 
            root.left = self.buildTree(preorder[1: index + 1], inorder[0: index])
        if index + 1 != len(inorder):
            root.right = self.buildTree(preorder[index + 1:], inorder[index + 1:])
        return root

def stringToIntegerList(input):
    import json
    return json.loads(input)

def treeNodeToString(root):
    if not root:
        return "[]"
    output = ""
    queue = [root]
    current = 0
    while current != len(queue):
        node = queue[current]
        current = current + 1

        if not node:
            output += "null, "
            continue

        output += str(node.val) + ", "
        queue.append(node.left)
        queue.append(node.right)
    return "[" + output[:-2] + "]"

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            preorder = stringToIntegerList(line)
            line = next(lines)
            inorder = stringToIntegerList(line)
            
            ret = Solution().buildTree(preorder, inorder)

            out = treeNodeToString(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()