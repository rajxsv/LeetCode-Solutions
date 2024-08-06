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

    bool solve(TreeNode* a, TreeNode* b) {
        if(!a || !b) return a==b;

        return a->val == b->val && solve(a->left,b->right) 
        && solve(a->right,b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return solve(root,root);
    }
};