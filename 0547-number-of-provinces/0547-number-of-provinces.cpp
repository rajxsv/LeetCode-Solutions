class Solution {
public:

    void dfs(int src,map<int,bool> &vis,map<int,vector<int>> &adj){
        vis[src]=true;
        for(auto nbr:adj[src]){
            if(!vis[nbr]){
                dfs(nbr,vis,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        map<int,vector<int>> adj;

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        map<int,bool> vis;

        for(auto p:adj){
            for(auto nbr:p.second){
                if(!vis[nbr]){
                    ans++;
                    dfs(nbr,vis,adj);
                }
            }
        }
        return ans;
    }
};