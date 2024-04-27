class Solution {
public:
    int dp[101][101];
    unordered_map<char,vector<int>> um;
    int n,r;
    
    int solve(int ind, string &pat,int c) {
        if(ind >= n) return 0;
        int ans = INT_MAX;
        if(dp[ind][c]!=-1) return dp[ind][c];
        for(auto i : um[pat[ind]]) {
            int ops = min(abs(i-c),r-abs(i-c));
            ans = min(ans,ops+solve(ind+1,pat,i));
        }
        return dp[ind][c] = ans;
    }
    
    int findRotateSteps(string ring, string key) {
        n = key.size();
        r = ring.size();
        for(int i=0; i<r; i++) um[ring[i]].push_back(i);
        memset(dp,-1,sizeof(dp));
        return solve(0,key,0) + key.size(); 
    }
};