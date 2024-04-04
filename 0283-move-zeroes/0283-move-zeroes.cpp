class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,r=0,n=nums.size();
        while(r<n&&l<n) {
            // get r to non zero and l to 0
            if(nums[r]==0) r++;
            else if(nums[l]!=0)l++;
            else if(l<r) swap(nums[l++],nums[r++]);
            else r++;
        }
    }
};