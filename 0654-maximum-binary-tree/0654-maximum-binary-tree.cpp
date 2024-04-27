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
    int len;
    TreeNode* solve(int i, int j, vector<int> &nums) {
        if(i>j) return nullptr;
        if(i==j) return new TreeNode(nums[i]);
        
        int ind = (max_element(begin(nums)+i,end(nums)-(len-1-j)) - begin(nums));
        
        TreeNode* n = new TreeNode(nums[ind]);
        n ->left = solve(i,ind-1,nums);
        n->right = solve(ind+1,j,nums);
        
        return n;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        len = nums.size();
        return solve(0,len-1,nums);
    }
};