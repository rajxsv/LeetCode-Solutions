class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m,0));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int sum = 0;

                for (int r=max(0,i-k); r<=min(n-1,i+k); r++) {
                    for (int c=max(0,j-k); c<=min(m-1,j+k); c++) {
                        sum += mat[r][c];
                    }
                }

                ans[i][j] = sum;
            }
        }

        return ans;
    }
};