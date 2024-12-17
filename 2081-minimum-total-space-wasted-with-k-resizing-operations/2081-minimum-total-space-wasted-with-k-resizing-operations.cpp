class Solution {
public:
    int dp[201][201];

    int solve(vector<int> &nums, int ind, int k) {
        int n = nums.size();
        if(ind == n) return 0;
        if(k < 0) return 1e8;
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int mx = nums[ind];
        int sum = 0;
        int ans = 1e8;

        for(int i=ind; i<n; i++) {
            mx = max(mx,nums[i]);
            sum += nums[i];

            int waste = mx*(i-ind+1) - sum;
            ans = min(ans, waste + solve(nums,i+1, k-1));
        }

        return dp[ind][k] = ans;
    }

    // 10,20  0,0
    // 

    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,k);
    }
};