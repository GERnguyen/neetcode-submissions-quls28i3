# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if (p is None) == (q is None):
            if p == None:
                return True
        else: return False
        queue1, queue2 = [p], [q]
        while queue1 and queue2:
            cur1 = queue1.pop(0)
            cur2 = queue2.pop(0)

            if cur1.val != cur2.val: return False

            if (cur1.left is None) == (cur2.left is None):
                if cur1.left != None:
                    queue1.append(cur1.left)
                    queue2.append(cur2.left)
            else:
                return False

            if (cur1.right is None) == (cur2.right is None):
                if cur1.right != None:
                    queue1.append(cur1.right)
                    queue2.append(cur2.right)
            else:
                return False
        
        return True