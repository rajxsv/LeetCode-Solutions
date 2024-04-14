class RecentCounter {
private:
    vector<int> calls;
    int size;
public:
    RecentCounter() {
        this->size=0;
    }
    
    int binary_search(int t) {
        int n=size;
        int l=0;
        int h=n-1;
        int target = max(0,t-3000);
        int res=-1;
        
        // t -> 4000 
        // get to index 4000-3000 
        // 1 2 3 900 2000 3000 3000 4000 5000
        // 4 ind (5 ans)-> (9-4) -> 5
        // find greater than equal to target (smallest)
        
        while(l<=h) {
            int mid=(l+h)/2;
            if(calls[mid]>=target) {
                res=mid;
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return res==-1?-1:n-res;
    }
    
    int ping(int t) {
        calls.push_back(t);
        size++;
        int find = binary_search(t);
        return find;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */