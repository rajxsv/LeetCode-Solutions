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
    int preIdx = 0;

    TreeNode* f(vector<int> &pre,vector<int> &in,int s,int e){
        if(s>e){
            return NULL;
        }

        TreeNode* node = new TreeNode(pre[preIdx]);

        int inIdx = -1;
        for(int j=s;j<=e;j++){
            if(pre[preIdx] == in[j]){
                inIdx=j;
                break;
            }
        }

        preIdx++;

        node->left = f(pre,in,s,inIdx-1);
        node->right = f(pre,in,inIdx+1,e);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int n = inorder.size();
        return f(preorder,inorder,0,n-1); // 2 things in tells us wich elements are on left or right 
                                //   pre tells us which is next basically the root 
    }
};