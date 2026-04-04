# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def DFS(self, root, p, q):
        stack = [root]      
        v1, v2 = q.val, p.val

        while stack:
            n = stack.pop()
            if (v1 <= n.val <= v2)  or (v1 >= n.val >= v2): return n
            if v1 < n.val and v2 < n.val:
                if n.left:
                    stack.append(n.left)
            else:
                if n.right:
                    stack.append(n.right)
        
        return root


            

    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        return self.DFS(root, p, q)