class Solution {
public:
    vector<int> topo(vector<int> &in, int m, unordered_map<int,vector<int>> &adj) {
        queue<int> q;
        vector<int> res;

        for(int i=0; i<m; i++) {
            if(in[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto nbr : adj[node]) {
                in[nbr]--;
                if(in[nbr] == 0) {
                    q.push(nbr);
                    res.push_back(nbr);
                }
            }
        }
        if(res.size() == m) {
            return res;
        }

        return {};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int,vector<int>> groupDetails;
        unordered_map<int,int> hasGroup;
        unordered_map<int,vector<int>> adj; // has the grouping ordering
        unordered_map<int,vector<int>> adj2; // has the internal grouping

        for(int i=0; i<n; i++) {
            if(group[i] != -1) {
                groupDetails[group[i]].push_back(i);
                hasGroup[i] = group[i];
            } else {
                groupDetails[m].push_back(i);
                hasGroup[i] = m;
                m++;
            }
        }
        vector<int> in1(m,0);
        vector<int> in2(n,0);

        for(int i=0; i<n; i++) {
            int pointsTo = hasGroup[i];
            for(auto it:beforeItems[i]) {
                if(hasGroup[it] != hasGroup[i]) {
                    adj[hasGroup[it]].push_back(pointsTo);
                    in1[pointsTo]++;
                }
                else {
                    adj2[it].push_back(i);
                    in2[i]++;
                }
            }
        }

        vector<int> resg = topo(in1,m,adj);
        if(resg.size() == 0) return {};
        vector<int> resi = topo(in2,n,adj2);
        if(resi.size() == 0) return {};
        unordered_map<int,vector<int>> um;
        vector<int> res;

        for(int i=0; i<n; i++) {
            um[hasGroup[resi[i]]].push_back(i); 
        }

        for(auto it : resg) {
            for(auto it2 : um[it]) {
                res.push_back(resi[it2]);
            }
        }

        return res;
    }
};