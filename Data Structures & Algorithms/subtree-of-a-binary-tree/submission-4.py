# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def candidates_search(self, root, start):
        queue = [root]
        candidates = []

        while queue:
            n = queue.pop(0)
            if n.val == start: candidates.append(n)
            if n.left: queue.append(n.left)
            if n.right: queue.append(n.right)

        return candidates

        
    def checker(self, r1, r2):
        q1, q2 = [r1], [r2]

        while q1 and q2:
            n1 = q1.pop(0)
            n2 = q2.pop(0)
            if (n1.val != n2.val): return False
            if n1.left: q1.append(n1.left)
            if n1.right: q1.append(n1.right)
            if n2.left: q2.append(n2.left)
            if n2.right: q2.append(n2.right)
        
        return len(q1) == len(q2)

                   
        


    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        candidates = self.candidates_search(root, subRoot.val)

        if len(candidates) == 0: return False

        for c in candidates:
            if self.checker(c, subRoot) == True: return True
        return False

