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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* second = slow -> next;
        slow -> next = nullptr;
        second = reverse(second);

        ListNode* first = head;

        while (second) {
            ListNode* tmp1 = first -> next;
            ListNode* tmp2 = second -> next;

            first -> next = second;
            second -> next = tmp1;

            second = tmp2;
            first = tmp1;
        }
        

    }
};
