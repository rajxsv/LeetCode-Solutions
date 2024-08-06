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
class bstIterator{
    stack<TreeNode*> stL;
    stack<TreeNode*> stR;
public:

    bstIterator(TreeNode* root){
        pushLeft(root);
        pushRight(root);
    }    

    void pushLeft(TreeNode* root){
        while(root){
            stL.push(root);
            root = root->left;
        }
    }
    void pushRight(TreeNode* root){
        while(root){
            stR.push(root);
            root = root->right;
        }
    }
    int next(){
        if(stL.empty()){
            return -1;
        }
        auto res = stL.top();
        stL.pop();

        pushLeft(res->right);
        return res->val;
    }
    int before(){
        if(stR.empty()){
            return -1;
        }
        auto res = stR.top();
        stR.pop();

        pushRight(res->left);
        return res->val;
    }
};
class Solution {
public:


    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        
        bstIterator* it = new bstIterator(root);

        int left = it->next();
        int right = it->before();

        while(left < right){
            if(left + right < k){
                left = it->next();
            }else if(left + right > k){
                right = it->before();
            }else{
                return true;
            }
        }
        return false;

    }
};