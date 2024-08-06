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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<vector<int>> res;    
        vector<int> sm;
        

        
        int mode = 0;

        while(!q.empty()) {
            auto itr = q.front();
            q.pop();

            if(!itr){
                if(mode) reverse(sm.begin(), sm.end());
                mode ^= 1;

                if(sm.size()) res.push_back(sm);
                
                sm = {};

                if(q.empty()) break;
                q.push(NULL);
            } else {
                sm.push_back(itr->val);
                if(itr->left) {
                    q.push(itr->left);
                }
                if(itr->right){
                    q.push(itr->right);
                }
            }
        }
        return res;
    }
};