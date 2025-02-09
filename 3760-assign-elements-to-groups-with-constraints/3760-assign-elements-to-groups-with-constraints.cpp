class Solution {
public:
    unordered_map<int,int> um;

    int findFactorsReturnIndex(int num, vector<int> &aux, int m) {
        if(num==1) {
            return (um.find(1) == um.end()) ? m : um[1];
        }

        int res = m;

        for (int i=1; i<=sqrt(num); ++i) {
            if (num%i == 0) {
                if(um.find(i) != um.end()) res = min(res,um[i]);
                if (i*i != num && um.find((num/i)) != um.end()) res = min(res,um[num/i]);
            }
        }
        return res;
    }

    vector<int> assignElements(vector<int>& g, vector<int>& e) {
        int n = g.size();
        int m = e.size();
        vector<int> res(n,-1);

        for(int i=0; i<m; i++) {
            if(um.find(e[i]) == um.end()) um[e[i]] = i;
        }

        for(int i=0; i<n; i++) {
            vector<int> aux;
            res[i] = findFactorsReturnIndex(g[i],aux,m);
            if(res[i] == m) res[i] = -1;
        }

        return res;
    }
};