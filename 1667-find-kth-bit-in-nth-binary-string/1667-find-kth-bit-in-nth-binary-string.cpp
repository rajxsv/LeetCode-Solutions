class Solution {
public:
    string invert(string s) {
        for(int i=0;i<s.size();i++) s[i]=s[i]=='0'?'1':'0';
        return s;
    }
    char findKthBit(int n, int k) {
        vector<string> dp(n);
        dp[0]="0";
        for(int i=1;i<n;i++){
            string aux=invert(dp[i-1]);
            reverse(begin(aux),end(aux));
            dp[i]=dp[i-1]+"1"+aux;
        }
        return dp[n-1][k-1];
    }
};