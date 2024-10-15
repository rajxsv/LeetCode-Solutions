class Solution {
public:
    long long minimumSteps(string s) {
        int o=0;
        long long swap=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')o++;
            else swap+=o;
        }
        return swap;
    }
};