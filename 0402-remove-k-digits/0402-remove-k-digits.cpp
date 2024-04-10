class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto ch:num) {
            while(!st.empty() && k>0 && st.top()>ch){
                st.pop();
                k--;
            }
            if(!st.empty() || ch!='0') st.push(ch);  // if empty then dont push 0
        }
        while(!st.empty()&&k>0){
            st.pop();
            k--;
        }
        if(st.empty())return "0";
        string res="";
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};