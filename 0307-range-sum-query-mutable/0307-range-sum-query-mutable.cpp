class NumArray {
    vector<int> seg,nums;
    int n;

    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(n*4);
        this->nums = nums;
        buildTree(0,0,n-1);
    }
    
    void buildTree(int idx, int s, int e) {
        if(s==e) {
            seg[idx]=nums[s];    
            return;
        }
        
        int mid = (s+e)/2;
        
        buildTree(2*idx+1,s,mid);
        buildTree(2*idx+2,mid+1,e);
        
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    void updateBuild(int index, int val, int idx, int s, int e) {
        if(index<s || index>e || s==e) {
            if(index==s) seg[idx] = val;
            return;
        }
        
        int mid = (s+e)/2;
        
        updateBuild(index,val,2*idx+1,s,mid);
        updateBuild(index,val,2*idx+2,mid+1,e);
        
        seg[idx] = seg[2*idx+1]+seg[2*idx+2];
    }
    
    void update(int index, int val) {
        updateBuild(index,val,0,0,n-1);   
    }
    
    int getSum(int idx,int s, int e, int l, int r) {
        if(r<s || l>e) return 0;
        if(l<=s && r>=e) return seg[idx];
        int mid = (s+e)/2;
        return getSum(2*idx+1,s,mid,l,r) + getSum(2*idx+2,mid+1,e,l,r);
    }
    
    int sumRange(int left, int right) {
        return getSum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */