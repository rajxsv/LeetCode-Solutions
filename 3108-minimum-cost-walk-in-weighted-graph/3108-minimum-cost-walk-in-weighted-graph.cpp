class Solution {
public:
    
    class DSU {
        public:
        
        vector<int> par;
        vector<int> size;
        vector<int> wt;
        
        DSU(int n) {
            par=vector<int>(n,0);
            for(int i=0;i<n;i++) par[i]=i;
            size=vector<int>(n,0);
            for(int i=0;i<n;i++) size[i]=1;
            wt=vector<int>(n,INT_MAX);
        }
        
        int findPar(int u) {
            if(par[u]==u) return u;
            return par[u]=findPar(par[u]);
        }
        
        void unionBySize(int s, int d, int w) {
            int sp=findPar(s);
            int dp=findPar(d);
            if(sp==dp) {
                wt[sp]=wt[dp]=wt[sp]&wt[dp]&w;
            } else if(size[sp]>size[dp]) {
                size[sp]+=size[dp];
                par[dp]=par[sp];
                wt[sp]=wt[dp]=wt[sp]&wt[dp]&w;
            } else {
                size[dp]+=size[sp];
                par[sp]=par[dp];
                wt[dp]=wt[sp]=wt[dp]&wt[sp]&w;
            }
        }
        
    };
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU* dsu=new DSU(n);
        vector<int> res;
        
        for(auto it:edges) {
            int s=it[0];
            int d=it[1];
            int w=it[2];
            
            dsu->unionBySize(s,d,w);
        }
        
        for(auto it:query) {
            int s=it[0];
            int d=it[1];
            
            if(s==d) {
                res.push_back(0);
                continue;
            }
                
            int sp=dsu->findPar(s);
            int dp=dsu->findPar(d);
            
            if(sp==dp) {
                res.push_back(dsu->wt[sp]);
            } else {
                res.push_back(-1);
            }
        }
        
        return res;
    }
};