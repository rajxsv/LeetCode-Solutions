class Solution {
public:
    int n;
    void solve(string &preorder, int &ind){
        if(ind>=n || preorder[ind]=='#'){
            while(ind<n && preorder[ind]!=',')ind++;
            ind++;
            return;
        }
        while(ind<n && (preorder[ind] != ','))ind++;
        ind++;
        solve(preorder,ind);
        solve(preorder,ind);
    }
    bool isValidSerialization(string preorder) {
        n=preorder.size();
        int ind=0;
        solve(preorder,ind);
        cout<<ind<<endl;
        return ind==n+1;
    }
};