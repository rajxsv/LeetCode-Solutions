class Solution {
public:
    int n;

    int solve(vector<int>& pre, int ind, int k, int maxSum, vector<vector<int>>& dp) {
        if (k == 1) {
            return pre[n - 1] - (ind > 0 ? pre[ind - 1] : 0);
        }

        if(ind >= n) {
            return INT_MAX;
        }
        
        if (dp[ind][k] != -1) return dp[ind][k];

        int ans = INT_MAX;

        for (int i = ind; i < n; ++i) {
            int curSum = pre[i] - (ind > 0 ? pre[ind - 1] : 0);

            if (curSum > ans) break;

            int nextSplit = solve(pre, i + 1, k - 1, max(maxSum, curSum), dp);
            ans = min(ans, max(curSum, nextSplit));
        }

        return dp[ind][k] = ans;
    }

    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            pre[i] = nums[i] + pre[i - 1];
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(pre, 0, k, 0, dp);
    }
};
