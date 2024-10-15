class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        long long ans=0;
        for(auto it:nums) {
            pq.push(it);
        }
        while(k-- && !pq.empty()) {
            long long top=pq.top();
            pq.pop();
            ans+=top;
            if((top%3)!=0){
                pq.push((top/(long long)(3)) + 1);
            } else {
                pq.push(top/(long long)(3));
            }
        }   
        return ans;
    }
};