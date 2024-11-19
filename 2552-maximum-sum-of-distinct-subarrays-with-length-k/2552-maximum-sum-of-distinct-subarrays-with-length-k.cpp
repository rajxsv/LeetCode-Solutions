class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size();
        int j = 0;
        long long res = 0;
        long long sum = 0;

        for(int i=0; i<n; i++) {
            while(j<n && freq.find(nums[j]) == freq.end() && freq.size() < k) {
                sum += nums[j];
                freq[nums[j]] = 1;
                j++;
            }

            if(freq.size() == k) {
                res = max(res,sum);
            }

            freq.erase(nums[i]);
            sum -= nums[i];
        }

        return res;
    }
};