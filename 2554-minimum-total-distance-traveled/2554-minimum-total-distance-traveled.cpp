class Solution {
public:
    long long solve(vector<int> &rbt, int rbtInd, vector<int> &fct, int fctInd, vector<vector<long long>> &dp) {
        if (rbtInd == rbt.size()) return 0;
        if (fctInd == fct.size()) return 1e12;
        
        if(dp[rbtInd][fctInd] != -1) return dp[rbtInd][fctInd];

        long long take = abs(rbt[rbtInd] - fct[fctInd]) + solve(rbt,rbtInd+1,fct,fctInd+1,dp);
        long long notTake = solve(rbt,rbtInd,fct,fctInd+1,dp);

        return dp[rbtInd][fctInd] = min(take,notTake);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> fact;
        int n = robot.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        for(auto f:factory) {
            while(f[1]--) {
                fact.push_back(f[0]);
            }
        }
        int m = fact.size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));
        return solve(robot,0,fact,0,dp);
    }
};