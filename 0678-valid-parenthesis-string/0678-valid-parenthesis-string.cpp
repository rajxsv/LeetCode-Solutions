class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stA;
        stack<int> stB;
        int n=s.size();
        for(int i=0; i<n; i++) {
            if(s[i]=='(') {
                stA.push(i);
            } else if(s[i]=='*') {
                stB.push(i);
            } else {
                if(!stA.empty()) stA.pop();
                else if(!stB.empty() && stB.top()<i) stB.pop();
                else return false;
            }
        }
        
        if(stA.empty()) return true;
        
        while(!stA.empty()) {
            if(!stB.empty() && stA.top() < stB.top()) {
                stA.pop();
                stB.pop();
            } else {
                return false;
            }
        }
        return true;
    }
};