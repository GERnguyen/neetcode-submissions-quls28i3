# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        Prev = None
        Cur = head
        

        while Cur != None:
            Next = Cur.next
            Cur.next = Prev
            Prev = Cur
            Cur = Next
        
        return Prev

