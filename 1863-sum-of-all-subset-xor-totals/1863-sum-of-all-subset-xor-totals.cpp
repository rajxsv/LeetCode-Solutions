class Solution {
public:
    
    vector<int> res;
    
    void solve(vector<int> &nums, int ind, int curXr) {
        if(ind<0) {
            res.push_back(curXr);
            return;
        }
        
        solve(nums,ind-1,curXr^nums[ind]);
        solve(nums,ind-1,curXr);
    }
    
    int subsetXORSum(vector<int>& nums) {
        int xr = 0;
        solve(nums,nums.size()-1,0);
        
        for(auto i:res) {
            xr += i;
        }
        
        return xr;
    }
};