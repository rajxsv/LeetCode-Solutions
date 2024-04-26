class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> um;
        for(auto i:nums) um[i]++;
        for(auto [key,value] : um) if(value%2 != 0) return false;
        
        return true;
    }
};