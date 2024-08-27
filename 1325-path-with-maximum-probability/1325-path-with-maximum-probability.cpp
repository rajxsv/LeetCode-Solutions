class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,float>>> adj;
        priority_queue<pair<float,int>> q;
        vector<float> prob(n,(float)0);

        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        q.push({(float)1,start_node});
        prob[start_node] = 1;

        while (!q.empty()) {
            float probTillNow = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto nbr : adj[node]) {
                int nbrNode = nbr.first;
                float nbrProb = nbr.second;

                if (probTillNow*nbrProb > prob[nbrNode]) {
                    q.push({probTillNow*nbrProb, nbrNode});
                    prob[nbrNode] = probTillNow*nbrProb;
                }
            }
        }

        return prob[end_node];
    }
};