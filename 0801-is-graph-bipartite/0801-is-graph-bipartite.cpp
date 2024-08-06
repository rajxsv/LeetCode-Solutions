class Solution {
public:
    // return true if bipatite
    unordered_map<int,int> bfs;

    bool BFS(int src,vector<int> &color,vector<vector<int>> &graph){
        queue<int> q;

        q.push(src);
        color[src] =0;   

        while(!q.empty()){
            int node = q.front();
            q.pop();

            bfs[node] = 1;

            for(auto nbr:graph[node]){

                if(color[nbr] == -1){
                    color[nbr] = !color[node];
                    q.push(nbr);
                }
                else if(color[nbr] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++){
            bfs[i] == 0;
        }

        for(int i=0;i<graph.size();i++){
            if((bfs[i] == 0) && (BFS(i,color,graph)==false)){
                return false;
            }
        }
        return true;
    }
};