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

    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }

        vector<int> res;
        TreeNode* cur = root;

        while(cur!=NULL){
            if(cur->left == NULL){
                res.push_back(cur->val);
                cur=cur->right;
            }else{
                TreeNode* rightMostLeft = cur->left;

                while((rightMostLeft->right != NULL) 
                &       rightMostLeft->right != cur){
                    rightMostLeft = rightMostLeft->right;
                }

                if(rightMostLeft->right == NULL){
                    res.push_back(cur->val); // making sure in pre root comes first
                    rightMostLeft->right = cur;
                    cur = cur->left;
                }else{
                    rightMostLeft->right = nullptr;
                    cur = cur->right;
                }
            }
        }

        return res;
    }
};