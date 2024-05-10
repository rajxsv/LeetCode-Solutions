class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int diff = 0;
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(n,0));

        while(diff < n) {
            dp[diff][diff] = 1;
            if(diff != n-1) {
                if(s[diff] == s[diff+1]) {
                    dp[diff][diff+1] = 2;
                    ans++;
                }
            }
            ans++;
            diff++;
        }

        diff = 2;
        int itr = n-1;

        for(int ii=0; ii<itr; ii++) {
            for(int i=0, j=i+diff; i<n && j<n; i++,j++) {
                if(s[i] == s[j]) {
                    if(dp[i+1][j-1] == 0) dp[i][j] = 0;
                    else {
                        dp[i][j] = dp[i+1][j-1] + 2;
                        ans++;
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
            diff++;
        }
        
        return ans;
    }
};