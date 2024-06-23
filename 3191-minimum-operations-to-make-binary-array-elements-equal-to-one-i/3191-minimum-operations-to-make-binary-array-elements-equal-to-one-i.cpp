class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        for(int i=0; i<n-2; i++) {
            if(nums[i]==0) {
                nums[i]=1;
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
                cnt++;
            }
        }
        
        return accumulate(begin(nums),end(nums),0)==n ? cnt : -1;  
    }
};