class Solution {
public:
    int n,m;
    int islandPerimeter(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j]) continue;
                int up=(i==0?1:(grid[i-1][j]==0));
                int right=(j==m-1?1:(grid[i][j+1]==0));
                int down=(i==n-1?1:(grid[i+1][j]==0));
                int left=(j==0?1:(grid[i][j-1]==0));
                res+=up+down+left+right;
            }
        }
        return res;
    }
};