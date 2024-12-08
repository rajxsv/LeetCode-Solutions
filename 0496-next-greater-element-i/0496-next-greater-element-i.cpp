class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // if empty -> push
        // if top
            // smaller -> pop it push
            // bigger -> push
        unordered_map<int,int> um;
        stack<int> st;
        vector<int> res;
        int m = nums2.size();
        int n = nums1.size();
        for(int i=m-1; i>=0 ;i--) {
            while(!st.empty() && nums2[st.top()] <= nums2[i]) {
                st.pop();
            }
            um[nums2[i]] = st.empty() ? -1 : nums2[st.top()];
            st.push(i);
        }
        for(int i=0; i<n; i++) {
            res.push_back(um[nums1[i]]);
        }
        return res;
    }
};