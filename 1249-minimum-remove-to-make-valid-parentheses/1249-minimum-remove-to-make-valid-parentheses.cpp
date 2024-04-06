class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<pair<char,int>> st;
        vector<int> notValid(n); // 1 means not valid
        string res="";
        
        for(int i=0;i<n;i++) {
            if(s[i]=='(') {
                st.push({s[i],i});
            } else if(s[i]==')') {
                if(!st.empty() && st.top().first=='(') {
                    // valid pair
                    st.pop();
                } else {
                    notValid[i]=1;
                }
            }
        }
        
        while(!st.empty()) {
            notValid[st.top().second]=1;
            st.pop();
        }
        
        for(int i=0;i<n;i++){
            if(notValid[i])continue;
            res+=s[i];
        }
        
        return res;
    }
};