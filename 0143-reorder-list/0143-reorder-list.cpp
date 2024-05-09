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
        if(!head) return;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* right = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        
        // rxeverse the second part 
        
        while(right) {
            ListNode* n = right->next;
            right->next = prev;
            
            prev = right;
            right = n;
        }
        
        right = prev;
        ListNode* left = head;
        
        while(left && right) {
            ListNode* nLeft = left->next;
            ListNode* nRight = right->next;
            
            left->next = right;
            right->next = nLeft;
            
            left = nLeft;
            right = nRight;
        }
        
    }
};