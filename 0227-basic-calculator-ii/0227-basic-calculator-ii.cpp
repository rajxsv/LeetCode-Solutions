class Solution {
public:
    int calculate(string s) {
        vector<int> res;
        char op='+';
        s+="$";
        int curr=0,ans=0;
        int n=s.size();
        
        for(int i=0;i<n;i++) {
            if(s[i]>='0' && s[i]<='9') curr = curr*10 + (s[i]-'0');
            else if(s[i]!=' ') {
                if(op =='+' || op =='-') {
                    res.push_back(curr*(op=='-'?-1:1));
                } else {
                    res[res.size()-1]=op=='*'?curr*res[res.size()-1]:res[res.size()-1]/curr;
                }
                op = s[i];
                curr = 0;
            }
        }
        
        for(auto num:res) ans += num;
        return ans;
    }
};