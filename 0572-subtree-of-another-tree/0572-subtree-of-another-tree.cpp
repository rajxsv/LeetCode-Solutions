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
    
    bool check(TreeNode* root, TreeNode* subTree) {
        if(!root || !subTree) return root == subTree;
        return root->val == subTree->val && check(root->left,subTree->left) && check(root->right,subTree->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return root == subRoot;
        return check(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};