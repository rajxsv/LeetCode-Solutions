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
    int ans=0;
    int solve(TreeNode* root) {
        if(!root || (!root->left&&!root->right)) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int res=0;
        if(root->left&&root->left->val==root->val) res+=1+left;
        if(root->right&&root->right->val==root->val) res+=1+right;
        ans=max(res,ans);
        return root->left&&root->left->val==root->val && root->right&&root->right->val==root->val ? max(1+left,1+right) : res;
        
    }
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return ans;
    }
};