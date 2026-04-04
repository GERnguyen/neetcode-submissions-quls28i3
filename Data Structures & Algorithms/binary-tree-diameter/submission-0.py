# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.ans = 0
    def bt(self, node, depth):
        l, r = 0, 0
        if node.left != None:
            l = self.bt(node.left, depth + 1)
        if node.right != None:
            r = self.bt(node.right, depth + 1)
        if node.left == None and node.right == None: 
            return depth
        self.ans = max(self.ans, (l - depth) + (r - depth) )
        return max(l, r)
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root == None: return 0
        _ = self.bt(root, 0)
        return self.ans