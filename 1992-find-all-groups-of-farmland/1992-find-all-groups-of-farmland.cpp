class Solution {
public:
    vector<int> cord;
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    int n,m;
    
    Solution() {
        cord = vector<int>(4);
    }
    
    void bfs(vector<vector<int>> &land, int i, int j) {
        if(i>=n || j>=m || i<0 || j<0 || !land[i][j]) return;
        
        land[i][j]=0;
        
        cord[0] = min(cord[0],i);
        cord[1] = min(cord[1],j);
        cord[2] = max(cord[2],i);
        cord[3] = max(cord[3],j);
        
        for(int k=0;k<4;k++) {
            bfs(land,i+dx[k],j+dy[k]);
        }
    }
    
    void refresh(vector<int> &cord) {
        cord[0] = cord[1] = INT_MAX;
        cord[2] = cord[3] = INT_MIN;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        vector<vector<int>> res;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!land[i][j]) continue;
                refresh(cord);
                bfs(land,i,j);
                res.push_back(cord);
            }
        }
        
        return res;
    }
};