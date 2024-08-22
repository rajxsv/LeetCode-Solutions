class Solution {
public:

    int solve(int l, int r, string &s, vector<vector<int>> &dp) {
        if (l > r) {
            return 0;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        char ch = s[l];
        int ans = 1 + solve(l+1, r, s, dp);

        for (int k=l+1; k<=r; k++) {
            if (s[k] == ch) {
                ans = min(ans, solve(l, k-1, s, dp) + solve(k+1, r, s, dp));
            }
        } 

        return dp[l][r] = ans;
    }

    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, s, dp);
    }
};