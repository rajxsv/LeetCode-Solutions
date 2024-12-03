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
        if(!head) return head;

        Node* itr = head;
        Node* front;
        
        while(itr) {
            front = itr->next;
            Node* newNode = new Node(itr->val);

            itr->next = newNode;
            newNode->next = front;

            itr = front; 
        }

        itr = head;

        while(itr) {
            if(itr->random) {
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }

        itr = head;
        Node* copy = new Node(0);
        Node* res = copy;

        while(itr) {
            front = itr->next->next;

            copy->next = itr->next;

            itr->next = front;
            itr = itr->next;

            copy = copy->next;
        }

        return res->next;
    }
};