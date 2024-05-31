class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            xr ^= nums[i];    
        }
        
        int ind = -1;
        for(int i=31; i>=0; i--) {
            int mask = (1<<i);
            if(mask&xr) {
                ind = i;
                break;
            }
        }
        
        int mask = (1<<ind);
        
        int a = 0;
        for(int i=0; i<n; i++) {
            if(mask&nums[i]) a ^= nums[i];
        }
        
        return {a,xr^a};
    }
};