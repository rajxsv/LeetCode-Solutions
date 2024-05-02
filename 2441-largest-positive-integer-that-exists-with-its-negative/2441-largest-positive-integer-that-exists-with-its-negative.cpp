class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        unordered_map<int,int> um;
        for(auto i:nums) um[i]++;
        for(int i=n-1; i>=0; i--) {
            if(nums[i]>0 && um[-nums[i]]) {
                return nums[i];
            }
        }
        return -1;
    }
};