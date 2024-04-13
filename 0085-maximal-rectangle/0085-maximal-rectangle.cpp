class Solution {
public:

    int solve(vector<int> v) {
        int n = v.size();

        vector<int> leftSmaller(n);
        vector<int> rightSmaller(n);
        vector<int> res(n);

        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && v[st.top()] >= v[i]) st.pop();
            leftSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && v[st.top()] >= v[i]) st.pop();
            rightSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        int area = 0;
        for(int i=0; i<n; i++) {
            area = max(area,(rightSmaller[i]-leftSmaller[i]-1)*v[i]);
        }

        return area;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> heights(col);

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == '1') {
                    heights[j]++;
                }else{
                    heights[j] = 0;
                }
            }

            res = max(res, solve(heights));
        }
        return res;
    }
};