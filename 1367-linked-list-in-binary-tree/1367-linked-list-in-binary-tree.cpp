class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root){
            if(isEqual(head, root)){
                return true;
            }
            return isSubPath(head, root->left) || isSubPath(head, root->right);
        }
        return false;
    }
    bool isEqual(ListNode* head, TreeNode* root){
        if(!head){
            return true;
        }
        if(!root){
            return false;
        }
        return head->val == root->val && (isEqual(head->next, root->left) || isEqual(head->next, root->right));
    }
};