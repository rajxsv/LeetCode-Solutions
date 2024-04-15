class Solution {
public:
    int n;
    int solve(vector<int> &nums, int ind, int f, vector<vector<int>> &dp) {
        if(ind>=n) return 0;
        if(ind==n-1) {
            if(f) return 0;
            else return nums[ind];
        } 
        if(dp[ind][f]!=-1) return dp[ind][f];
        int take = nums[ind] + solve(nums,ind+2,(ind==0?1:f),dp);
        int notTake = solve(nums,ind+1,f,dp);
        
        return dp[ind][f] = max(take,notTake);
        
    }
    
    int rob(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(nums,0,0,dp);
    }
};