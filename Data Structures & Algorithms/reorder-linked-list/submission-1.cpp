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
    void reorderList(ListNode* head) {
        vector<ListNode*> ls;

        ListNode* tmp = head;

        while (tmp) {
            ls.push_back(tmp);
            tmp = tmp -> next;
        }

        int n = ls.size();
        int cur = 1;
        for (int i = 0; i < n / 2; i++) {
            ListNode* tail = ls.back();
            ls.pop_back();
            ls.insert(ls.begin() + cur, tail);
            cur += 2;
        }
        
        for (int i = 0; i < n - 1; i++) {
            ls[i] -> next = ls[i+1];
        }
        ls[n - 1] -> next = nullptr;
        head = ls[0];
    }
};
