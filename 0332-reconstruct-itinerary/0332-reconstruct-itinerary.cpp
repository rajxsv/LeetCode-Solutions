class Solution {
public:
    vector<string> res;
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> um;
    
    void dfs(string s) {
        while(!um[s].empty()) {
            string next = um[s].top();
            um[s].pop();
            dfs(next);
        }
        res.push_back(s);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it:tickets) {
            um[it[0]].push(it[1]);
        }
        
        dfs("JFK");
        reverse(begin(res),end(res));
        return res;
    }
};