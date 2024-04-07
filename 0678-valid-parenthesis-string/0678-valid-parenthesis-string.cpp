class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char,int>> stA;
        stack<pair<char,int>> stB;
        int n=s.size();
        for(int i=0; i<n; i++) {
            if(s[i]=='(') {
                stA.push({s[i],i});
            } else if(s[i]=='*') {
                stB.push({s[i],i});
            } else {
                if(!stA.empty() && stA.top().first=='(') stA.pop();
                else if(!stB.empty() && stB.top().second<i) stB.pop();
                else return false;
            }
        }
        
        if(stA.empty()) return true;
        
        while(!stA.empty()) {
            if(!stB.empty() && stA.top().second < stB.top().second) {
                stA.pop();
                stB.pop();
            } else {
                return false;
            }
        }
        return true;
    }
};