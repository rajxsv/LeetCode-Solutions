class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        queue<int> q;
        vector<int> degree(n),res;
        unordered_map<int,vector<int>> adj;
        int size,u,v;
        for(auto it:edges) {
            u=it[0];
            v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        for(int i=0;i<n;i++) {
            if(degree[i]==1) q.push(i);
        }
        while(n>2){
            size=q.size();
            n-=size;
            while(size--) {
                int node=q.front(); 
                q.pop();
                for(auto nbr:adj[node]) {
                    degree[nbr]--;
                    if(degree[nbr]==1) q.push(nbr);
                }
            }
        }
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};