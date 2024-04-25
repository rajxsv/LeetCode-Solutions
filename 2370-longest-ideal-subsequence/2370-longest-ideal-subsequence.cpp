class Solution {
public:

    int solve(vector<int> &nums, int ind, int next, int &k, vector<vector<int>> &dp) {
        if(ind < 0) return 0;
        if(dp[ind][next+1] != -1) return dp[ind][next+1];
        int take = 0;
        if(next == -1 || abs(next-nums[ind])<=k) {
            take = 1 + solve(nums,ind-1,nums[ind],k,dp);
        }
        int notTake = solve(nums,ind-1,next,k,dp);
        return dp[ind][next+1] = max(take,notTake);
    }
    
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<int> nums(n);
        
        for(int i=0; i<n; i++) nums[i] = (int)(s[i]-'a');
        vector<vector<int>> dp(n,vector<int>(*max_element(begin(nums),end(nums))+3,-1));
        return solve(nums,n-1,-1,k,dp);
    }
};