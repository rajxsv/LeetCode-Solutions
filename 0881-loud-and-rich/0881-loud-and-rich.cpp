class Solution {
private:
    int solve(int src, vector<vector<int>> &adj, vector<int> &quiet, vector<int> &memo) {
        if (memo[src] != -1) {
            return memo[src]; 
        }

        int resNode = src; 

        for (auto nbr : adj[src]) {
            int candidate = solve(nbr, adj, quiet, memo);
            if (quiet[candidate] < quiet[resNode]) {
                resNode = candidate;
            }
        }

        memo[src] = resNode; 
        return resNode;
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> res(n);
        vector<int> memo(n, -1); 

        for (auto it : richer) {
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < n; i++) {
            res[i] = solve(i, adj, quiet, memo);
        }

        return res;
    }
};
