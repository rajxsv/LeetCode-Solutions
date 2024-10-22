class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        unordered_map<int,vector<int>> adj;
        int n=nums.size();
        vector<int> inDegree(n,0);
        queue<int> q;

        for(auto seq:sequences) {
            for(int i=1;i<seq.size();i++) {
                adj[seq[i-1]-1].push_back(seq[i]-1);
                inDegree[seq[i]-1]++;
            }
        }
        for(int i=0;i<n;i++) {
            if(inDegree[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node=q.front();

            if(q.size()>1) {
                return false;    
            }
            q.pop();
            

            for(auto nbr:adj[node]) {
                inDegree[nbr]--;
                if(inDegree[nbr]==0) {
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};