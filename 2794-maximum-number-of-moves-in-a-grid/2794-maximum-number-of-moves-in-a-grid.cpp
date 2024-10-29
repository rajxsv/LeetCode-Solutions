class Solution {
public:
    int n, m;

    int solve(vector<vector<int>>& grid, int i, int j, int prev, vector<vector<int>> &dp) {
        if(i < 0 || j >= m || i >= n || grid[i][j] <= prev) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 1 + max({
            solve(grid, i-1, j+1, grid[i][j], dp), 
            solve(grid, i, j+1, grid[i][j], dp), 
            solve(grid, i+1, j+1, grid[i][j], dp)
            });

        return dp[i][j] = ans;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i=0; i<n; i++) {
            ans = max(ans, solve(grid, i, 0, -1, dp));
        }

        return ans - 1;
    }
};