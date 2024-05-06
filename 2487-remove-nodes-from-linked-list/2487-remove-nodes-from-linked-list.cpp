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
    ListNode* removeNodes(ListNode* head) {
        priority_queue<int,vector<int>,greater<int>> pq;
        ListNode* n = head;
        
        while(n) {
            while(!pq.empty() && pq.top() < n->val) pq.pop();
            pq.push(n->val);
            n=n->next;
        }
        
        ListNode* right = NULL;
        ListNode* cur = new ListNode(-1);
        
        while(!pq.empty()) {
            cur = new ListNode(pq.top());
            cur->next = right;
            right = cur;
            pq.pop();
        }
        return right;
        
    }
};