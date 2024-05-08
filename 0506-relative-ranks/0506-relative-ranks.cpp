class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<string,int>> v;
        int n = score.size();
        vector<string> res;
        
        for(int i=0; i<n; i++) {
            v.push_back({to_string(score[i]),i});
        }
        
        sort(begin(v),end(v),[&](pair<string,int> a, pair<string,int> b) {
            return stoi(a.first) > stoi(b.first);
        });
        
        for(int i=0; i<n; i++) {
            if(i==0) {
                v[i].first = "Gold Medal";
            } else if(i==1) {
                v[i].first = "Silver Medal";
            } else if(i==2) {
                v[i].first = "Bronze Medal";
            } else {
                v[i].first = to_string(i+1);
            }
        }
        
        sort(begin(v),end(v),[&](pair<string,int> a, pair<string,int> b) {
            return a.second < b.second;
        });
        
        for(auto i:v) {
            res.push_back(i.first);
        }
        
        return res;
    }
};