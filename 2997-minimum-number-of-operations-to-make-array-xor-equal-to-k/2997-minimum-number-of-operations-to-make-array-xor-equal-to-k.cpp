class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int xr = 0; 
        int res = 0;
        
        for(int i=0; i<n; i++) {
            xr ^= nums[i];
        }
        
        for(int i=0; i<32; i++) {
            int mask = 1<<i;
            if((mask&xr) == (mask&k)) continue;
            res++;
        }
        return res;
    }
};