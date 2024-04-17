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
    priority_queue<string,vector<string>,greater<string>> pq;
    
    void solve(TreeNode* root, string path) {
        if(!root) return;
        path = string(1,root->val+'a') + path;
        
        if(!root->left && !root->right) {
            pq.push(path);
        }   
        solve(root->left,path);
        solve(root->right,path);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        char ch='a';
        return pq.top();
    }
};