# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.balance = True
    def bt(self, node, depth):
        l, r = depth, depth
        if node.left != None:
            l = self.bt(node.left, depth + 1)
        if node.right != None:
            r = self.bt(node.right, depth + 1)
        if node.left == None and node.right == None: return depth
        if abs(l - r) > 1:
            self.balance = False
        return max(l, r)
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root == None: return True
        _ = self.bt(root, 0)
        return self.balance