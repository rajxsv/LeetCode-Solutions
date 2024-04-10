class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int id, int vd) {
        set<int> s;
        s.insert(nums[0]);
        int n=nums.size();
        
        for(int i=1;i<n;i++) {
            auto it=s.lower_bound(nums[i]-vd);
            
            if(it!=s.end()&&abs(*it-nums[i])<=vd) return true;
            s.insert(nums[i]);
            if(s.size()>id) s.erase(nums[i-id]);
        }
        return false;
    }
};