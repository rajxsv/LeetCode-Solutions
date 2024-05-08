class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left = j+1;
                int right = n-1;

                long long sum1 = nums[i] + nums[j];

                while(left<right){
                    long long sum2 = nums[left] + nums[right];
                    if(sum1+sum2>target){
                        right--;
                    }else if(sum1+sum2<target){
                        left++;
                    }else{
                        vector<int> v = {nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(v);
                        while(left<n && nums[left] == v[2])left++;
                        while(right>=0 && nums[right] == v[3])right--;
                    }
                }
                while(i+1<n && nums[i] == nums[i+1])i++;
                while(j+1<n && nums[j] == nums[j+1])j++;
            }
        }
        return ans;
    }
};