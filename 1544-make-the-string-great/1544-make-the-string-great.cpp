class Solution {
public:
    string makeGood(string s) {
      stack<char> st;
      int n=s.size();
      for(int i=0;i<n;i++) {
        if(!st.empty() &&
                ( ((st.top()-'a')==(s[i]-'A')) || 
                   (st.top()-'A')==(s[i]-'a')) ) {
          st.pop(); 
        } else {
          st.push(s[i]);
        }
      }
      string res="";
      while(!st.empty()) {
        res+=st.top();
        st.pop();
      }
      reverse(begin(res),end(res));
      cout<<"\n";
      return res;
    }
};