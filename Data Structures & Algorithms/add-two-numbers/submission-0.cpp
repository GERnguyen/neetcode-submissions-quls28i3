/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* sumNode = &dummy;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1 -> val + l2 -> val + carry;
            carry = 0;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            } 
        
            sumNode -> next = new ListNode(sum);
            sumNode = sumNode -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while (l1) {
            int sum = l1 -> val + carry;
            carry = 0;
            if (sum >=10) {
                carry = 1;
                sum-=10;
            }  
            sumNode -> next = new ListNode(sum);
            sumNode = sumNode -> next;
            l1 = l1 -> next;
        }
        while (l2) {
            int sum = l2 -> val + carry;
            carry = 0;
            if (sum >=10) {
                carry = 1;
                sum-=10;
            }  
            sumNode -> next = new ListNode(sum);
            sumNode = sumNode -> next;
            l2 = l2 -> next;
        }
        if (carry) sumNode -> next = new ListNode(1);
        
        return dummy.next;
    }
};
