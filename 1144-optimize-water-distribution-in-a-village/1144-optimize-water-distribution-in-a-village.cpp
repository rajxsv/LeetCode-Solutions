class DSU {
    vector<int> par, size;

public:
    DSU(int n) {
        par.resize(n);
        size.resize(n);
        
        for(int i=0; i<n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unionSize(int x, int y) {
        int parx = find(x);
        int pary = find(y);

        if(parx == pary) return;

        if(size[parx] < size[pary]) {
            par[pary] = parx;
            size[parx] += size[pary];
        } else {
            par[parx] = pary;
            size[pary] += size[parx];
        }
    }
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<int>> edges;
        DSU dsu(n+1);
        int res = 0;
        
        for(auto it : pipes) {
            int h1 = it[0];
            int h2 = it[1];
            int wt = it[2];

            edges.push_back({wt, h1, h2});
            edges.push_back({wt, h2, h1});
        }

        for(int i=0; i < wells.size(); i++) {
            edges.push_back({wells[i], 0, i+1});
            edges.push_back({wells[i], i+1, 0});
        }

        sort(begin(edges), end(edges));

        for(auto it : edges) {
            int wt = it[0];
            int x = it[1];
            int y = it[2];

            if(dsu.find(x) != dsu.find(y)) {
                dsu.unionSize(x, y);
                res += wt;
            }
        }

        return res;
    }
};