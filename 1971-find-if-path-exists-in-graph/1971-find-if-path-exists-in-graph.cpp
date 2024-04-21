class Solution {
public:

    bool dfs(int src, int dest, unordered_map<int,vector<int>> &adj, vector<int> &vis) {
        vis[src]=1;
        if(src==dest) return true;
        
        for(auto nbr:adj[src]) {
            if(!vis[nbr] && dfs(nbr,dest,adj,vis)) return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        unordered_map<int,vector<int>> adj;
        vector<int> vis(n,0);

        for(auto it:edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return dfs(source, destination, adj, vis);
    }
};