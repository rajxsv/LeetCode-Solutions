class Solution {
public:
    int n,m;
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        m = matrix[0].size();
        int res = INT_MIN;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i!=0) matrix[i][j] += matrix[i-1][j];
                if(j!=0) matrix[i][j] += matrix[i][j-1];
                if(i!=0 && j!=0) matrix[i][j] -= matrix[i-1][j-1];
            }
        }
        
        for(int r1 = 0; r1 < n; r1++) {
            for(int r2 = r1; r2 < n; r2++) {
                for(int c1 = 0; c1 < m; c1++) {
                    for(int c2 = c1; c2 < m; c2++) {
                        int sum = matrix[r2][c2];
                        if(r1 != 0) sum -= matrix[r1-1][c2];
                        if(c1 != 0) sum -= matrix[r2][c1-1];
                        if(r1 != 0 && c1 != 0) sum += matrix[r1-1][c1-1];
                    
                        if(sum <= k) res = max(res, sum);
                    }
                }
            }
        }
        
        return res;
    }
};
