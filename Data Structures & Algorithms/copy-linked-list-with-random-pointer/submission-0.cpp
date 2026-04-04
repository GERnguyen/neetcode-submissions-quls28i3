/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, int> index;
        map<int, Node*> index2;
        Node* it = head;
        int count = 0;
        while (it) {
            index[it] = count++;    //store index of nodes
            it = it -> next;
        }     

        Node dummy(0);
        Node* ans = &dummy;

        it = head;
        count = 0;
        while (it) {
            int value = it -> val;
            ans -> next = new Node(0);
            ans -> next -> val = value;
            ans = ans -> next;
            index2[count++] = ans;
            it = it -> next;
        }

        it = head;
        ans = &dummy;
        ans = ans -> next;
        while (it) {
            Node* rand = it -> random;
            if (index.find(rand) != index.end())    //if random is a node in the list
            {
                int i = index[rand];
                ans -> random = index2[i];
            }
            else {
                ans -> random = nullptr;
            }
            ans = ans -> next;
            it = it -> next;
        }

        return dummy.next;

    }
};
