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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int> &v, int l, int h) {
        if(l>h) return nullptr;
        int mid=(l+h)/2;
        TreeNode* n=new TreeNode(v[mid]);
        n->left=solve(v,l,mid-1);
        n->right=solve(v,mid+1,h);
        return n;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        int n=v.size();
        return solve(v,0,n-1);
    }
};