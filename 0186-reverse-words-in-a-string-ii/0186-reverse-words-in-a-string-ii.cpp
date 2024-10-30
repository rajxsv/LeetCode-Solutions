class Solution {
public:
    void reverseWords(vector<char>& s) {
        deque<char> dq;
        stack<char> st;
        int ind = 0;
        s.push_back(' ');

        for (auto ch : s) {
            if(ch == ' ') {
                while(!dq.empty()) {
                    st.push(dq.back());
                    dq.pop_back();
                }
                st.push(' '); 
            } else {
                dq.push_back(ch);
            }
        }
        st.pop();
        s.pop_back();

        while(!st.empty()) {
            
            s[ind] = st.top();
            st.pop();
            ind++;
        }
    }
};