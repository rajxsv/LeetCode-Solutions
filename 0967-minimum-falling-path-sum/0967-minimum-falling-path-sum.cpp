class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int dp[n][m];
        memset(dp,0,sizeof(dp));

        for(int j=0;j<m;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
 
                int a = 1e9;
                int b = 1e9; 
                int c = 1e9;

                if(j+1<m){
                    a = matrix[i][j] + dp[i-1][j+1];
                }

                if(j-1>=0){
                    b = matrix[i][j] + dp[i-1][j-1];
                }

                c = matrix[i][j] + dp[i-1][j];

                dp[i][j] = min({a,b,c});
            }
        }

        int ans = 1e9;

        for(int j=0;j<m;j++){
            ans = min(ans,dp[n-1][j]);
        }

        return ans;
    }
};