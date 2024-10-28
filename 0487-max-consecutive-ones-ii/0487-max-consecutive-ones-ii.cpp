class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int zeros = 0;
        int i = 0, j = 0;
        int n = nums.size();
        int ans = 0;

        while(j<n) {
            ones += (nums[j] == 1);
            zeros += (nums[j] == 0);
            j++;

            if(zeros <= 1) {
                ans = max(ans, ones+zeros);
            } else {
                while(i<n && zeros > 1) {
                    if(nums[i] == 1) {
                        ones--;
                    } else {
                        zeros--;
                    }
                    i++;
                }
                ans = max(ans, ones+zeros);
            }
        }

        return ans;
    }
};