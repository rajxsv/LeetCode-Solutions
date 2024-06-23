class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flag = 0, cnt = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]==flag) {
                flag=!flag;
                cnt++;
            }
        }
        return cnt;
    }
};