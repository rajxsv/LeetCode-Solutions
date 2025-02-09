class Solution {
public:

    void put(vector<vector<int>> &grid, vector<vector<int>> &mat) {
        int n = grid.size();
        for(int diff=0; diff<n; diff++) {
            int r = 0;
            int c = n-1-diff;
            vector<int> aux;
            while(r<n && c<n) {
                aux.push_back(grid[r][c]);
                r++; c++;
            }
            mat.push_back(aux);
        }

        for(int diff=1; diff<n; diff++) {
            int r = diff;
            int c = 0;
            vector<int> aux;
            while(r<n && c<n) {
                aux.push_back(grid[r][c]);
                r++; c++;
            }
            mat.push_back(aux);
        }
    }

     void putBack(vector<vector<int>> &mat, vector<vector<int>> &res) {
        // 1                     1  1  1
        // 1 2                   1  3  2 
        // 1 3 4   ->            1  2  4
        // 1 2 
        // 1
        int k = 0;
        int n = res.size();

        for(int diff=0; diff<n; diff++) {
            int r = 0;
            int c = n-1-diff;
            for(auto it:mat[k]) {
                res[r][c] = it;
                r++; c++;
            }
            k++;
        }
        for(int diff=1; diff<n; diff++) {
            int r = diff;
            int c = 0;
            for(auto it:mat[k]) {
                res[r][c] = it;
                r++; c++;
            }
            k++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> mat;
        int n = grid.size();
        vector<vector<int>> res(n,vector<int>(n,0));
        put(grid,mat);
        // for(auto it:mat) {
        //     for(auto it2:it) {
        //         cout << it2 << " ";
        //     }
        //     cout <<"\n";
        // }
        // return {};
        for(int i=0; i<n-1; i++) {
            sort(begin(mat[i]),end(mat[i]));
        }
        
        for(int i=n-1; i<mat.size(); i++) {
            sort(begin(mat[i]),end(mat[i]),greater<int>());
        }

        putBack(mat,res);

        // for(auto it:res) {
        //     for(auto it2:it) {
        //         cout << it2 << " ";
        //     }
        //     cout <<"\n";
        // }

        return res;
    }   
};