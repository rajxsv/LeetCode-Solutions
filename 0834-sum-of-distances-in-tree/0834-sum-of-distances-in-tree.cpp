class Solution { 
public: 
    void dfs(vector<vector<int>>& tree, int cur, int pre, vector<int>& res, vector<int>& count){
        for(auto next: tree[cur]){
            if(next == pre) continue;
            dfs(tree, next, cur, res, count);  
            res[cur] += res[next] + count[next]; 
            count[cur] += count[next];            
        }
        ++count[cur];
    }
    
    void dfS(vector<vector<int>>& tree, int cur, int pre, vector<int>& res, vector<int>& count){
        for(auto next: tree[cur]){
            if(next == pre) continue;
            res[next] = res[cur]-count[next] + count.size()-count[next]; 
            dfS(tree, next, cur, res, count); 
        }        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> res(n,0), count(n,0);
        vector<vector<int>> tree(n);
        for(auto& e: edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        dfs(tree, 0, -1, res, count);
        dfS(tree, 0, -1, res, count);
        return res;
    }
};