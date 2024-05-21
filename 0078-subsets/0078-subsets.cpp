class Solution {
public:
    
    vector<vector<int>> res;
    
    void solve(vector<int> nums, int ind, vector<int> &cur) {
        if(ind < 0) {
            res.push_back(cur);
            return;
        }
        
        solve(nums,ind-1,cur);
        
        cur.push_back(nums[ind]);
        solve(nums,ind-1,cur);
        cur.pop_back();
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> cur;
        solve(nums,n-1,cur);
        return res;
    }
};