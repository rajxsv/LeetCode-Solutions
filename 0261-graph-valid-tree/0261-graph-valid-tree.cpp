class Solution {
public:
    bool isTree(unordered_map<int,vector<int>> &adj, int node, vector<int> &path, int par) {
        path[node]=1;
        for(auto nbr:adj[node]) {
            if((par==-1 || nbr!=par) && (path[nbr] || !isTree(adj,nbr,path,node))) {
                return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        if(n==1) return 1;

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++) {
            if(adj[i].size()==1) {
                vector<int> path(n,0);
                bool ans = isTree(adj, i, path, -1);
                if(accumulate(path.begin(),path.end(),0)==n) return ans;
            }
        }
        return false;
        
    }
};