class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        int streakLen = 0;
        int nextNo = 0;

        int n = nums.size();

        for(int i = 0;i<n;i++){
            us.insert(nums[i]);
        }

        for(int i=0;i<n;i++){
            // the key here is to only check nums with no previous elements so they can be starting points
            if(us.find(nums[i]-1) == us.end()){
                int len = 1;
                int nextNo = nums[i]+1;
                us.erase(nums[i]);
                while(us.find(nextNo) != us.end()){
                    us.erase(nextNo);
                    nextNo++;
                    len++;
                }
                streakLen = max(streakLen,len);
            }
        }
        return streakLen;
    }
};