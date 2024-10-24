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

    void bfs(TreeNode* root, vector<int> &levelSums) {
        queue<TreeNode*> q;
        int levelSum=0;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            levelSum=0;
            while(size--) {
                TreeNode* top=q.front();
                q.pop();
                levelSum+=top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            levelSums.push_back(levelSum);
        }
    }

    void solve(TreeNode* &root, vector<int> &levelSums) {
        queue<TreeNode*> q;
        int level=1;
        root->val=0;
        q.push(root);

        while(!q.empty()) {
            int size=q.size();
            while(size--) {
                TreeNode* top=q.front();
                q.pop();
                int siblingSumNextLevel=(top->left?top->left->val:0) + (top->right?top->right->val:0);
                if(top->left){
                    top->left->val=levelSums[level]-siblingSumNextLevel;
                    q.push(top->left);
                }
                if(top->right){
                    top->right->val=levelSums[level]-siblingSumNextLevel;
                    q.push(top->right);
                }
            }
            level++;
        }
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSums;
        bfs(root,levelSums);
        solve(root,levelSums);
        return root;
    }
};