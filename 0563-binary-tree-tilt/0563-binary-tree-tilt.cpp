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
    int helper(TreeNode* &root) {
        if(!root) return 0;

        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        
        int value = root->val;
        
        root->val = abs(rightSum - leftSum);
        return value + leftSum + rightSum;
    }

    int dfs(TreeNode* root) {
        if(!root) return 0;
        return root->val + dfs(root->left) + dfs(root->right);
    }

    int findTilt(TreeNode* root) {
        helper(root);
    
        int sum = dfs(root);
        return sum;
    }
};