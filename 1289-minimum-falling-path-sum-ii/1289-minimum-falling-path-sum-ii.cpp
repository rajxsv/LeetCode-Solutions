class Solution {
public:
    int n,m;
    int dp[201][300];
    int solve(vector<vector<int>> &grid, int row, int prev) {
        if(row == n) return 0;
        if(dp[row][prev+100] != -1) return dp[row][prev+100];
        int mn=INT_MAX;
        for(int j=0; j<m; j++) {
            if(prev == -1 || j != prev) {
                mn = min(mn,grid[row][j]+solve(grid,row+1,j));
            }
        }
        return dp[row][prev+100] = mn;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,-1);
    }
};