class Solution {
private:
    int n;    
public:
    
    int solve(vector<int> h) {
        int m=h.size();
        vector<int> rightSmaller(m);
        vector<int> leftSmaller(m);
        stack<int> st;
        int res=0;
        
        for(int i=0;i<m;i++){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }

            leftSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty())st.pop();

        for(int i=m-1;i>=0;i--){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }

            rightSmaller[i] = st.empty() ? m : st.top();
            st.push(i);
        }
        
    
        
        for(int i=0;i<m;i++) {
            int side = min(h[i],rightSmaller[i]-leftSmaller[i]-1);
            res=max(res,side*side);
        }
        return res;
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        n=mat.size();
        int m=mat[0].size();
        vector<int> h(m,0);
        int ans=0;
        int f=0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]=='1') {
                    h[j]++;
                    f=1;
                } else {
                    h[j]=0;
                }
            }
            ans = max(ans,solve(h));
        }
        
        return ans==0?f:ans;
    }
};