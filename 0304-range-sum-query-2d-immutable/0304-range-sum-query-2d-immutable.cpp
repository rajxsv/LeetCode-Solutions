class NumMatrix {
private:
    vector<vector<int>> cumMat;
    int n;
    int m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        cumMat=matrix;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cumMat[i][j] +=   (j==0 ? 0 : cumMat[i][j-1]) 
                               + (i==0 ? 0 : cumMat[i-1][j]) 
                               - (((i==0) || (j==0)) ? 0 : cumMat[i-1][j-1]);
            }
        }
        
    }
    
    int sumRegion(int i1, int j1, int i2, int j2) {
        i1--; j1--; // Adjust indices to 0-based
        int sum = cumMat[i2][j2];
        
        if (i1 >= 0) sum -= cumMat[i1][j2];
        if (j1 >= 0) sum -= cumMat[i2][j1];
        if (i1 >= 0 && j1 >= 0) sum += cumMat[i1][j1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */