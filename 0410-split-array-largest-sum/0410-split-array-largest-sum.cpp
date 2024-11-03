class Solution {
public:

    int exists(vector<int> &nums, int k, int maxAllowed) {
        int currSum = 0;
        int n = nums.size();
        int splits = 0;

        for(int i=0; i<n; i++) {
            if(currSum + nums[i] <= maxAllowed) {
                currSum += nums[i];
            } else {
                currSum = nums[i];
                splits++;
            }
        }

        return splits+1;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(begin(nums),end(nums));
        int high = accumulate(begin(nums),end(nums),0);
        int ans = 0;

        while(low <= high) {
            int mid = (low+high)/2;
            int check = exists(nums,k,mid);

            if(check <= k) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }
};