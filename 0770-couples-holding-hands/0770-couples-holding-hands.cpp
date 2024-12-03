class Solution {
public:

    class DSU {
    public:
        vector<int> size, par;

        DSU(int n) {
            size.resize(n + 1, 1); 
            par.resize(n + 1);

            for (int i = 0; i <= n; i++) {
                par[i] = i;
            }
        }

        int find(int x) {
            if (par[x] == x) return x;
            return par[x] = find(par[x]); 
        }

        void unionBySize(int x, int y) {
            int px = find(x);
            int py = find(y);

            if (px == py) return;

            if (size[px] < size[py]) {
                par[px] = py;
                size[py] += size[px];
            } else {
                par[py] = px;
                size[px] += size[py];
            } 

            return; 
        }   
    };

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DSU d(n);

        for(int i=0; i<n; i+=2) {
            d.unionBySize(i,i+1);
        }

        int count = 0;

        //  we are forming 
        // groups from start if we think in a way that we are shuffling 
        // only the one we want to be at right place then the ones that are left 
        // in a connecged component are should be seated together and as 
        // the components reuduce to 1 all are seating together 

        for(int i=0; i<n; i+=2) {
            int x = d.find(row[i]);
            int y = d.find(row[i+1]);

            // its like everytime the least nodes that are not at right place are 2 
            // but as we add more componenets 2 are seated together and thus it 
            // stays as 2 and as we progress to 1 component the 2 seats actually 
            // become the connected couple that was required 

            if(x != y) {
                d.unionBySize(x,y);
                count++;
            }
        }

        return count;
    }
};