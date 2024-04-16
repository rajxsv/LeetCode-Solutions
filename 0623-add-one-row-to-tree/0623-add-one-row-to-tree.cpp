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
    // 0 means left
    
    TreeNode* solve(TreeNode* node, int &val, int &dep, int f, int lvl) {
        if(!node) {
            if(lvl==dep) return new TreeNode(val);
            return nullptr;
        }
        
        if(lvl==dep) {
            TreeNode* n = new TreeNode(val);
            if(f) {
                n->right=node;
            } else {
                n->left=node;
            }
            return n;
        }
        
        node->left = solve(node->left, val, dep, 0, lvl+1);
        node->right = solve(node->right, val, dep, 1, lvl+1);
        
        return node;
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return solve(root,val,depth,0,1);
    }
};