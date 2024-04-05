/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        
        queue<Node*> q;
        Node* pre, * curr; 
        int size;
        q.push(root);
        
        while(q.size()) {
            pre=nullptr;
            size=q.size();
            while(size--) {
                curr=q.front();
                q.pop();
                if(pre) {
                    pre->next=curr;
                }
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
                pre=curr;
            }
        }
        return root;
    }
};