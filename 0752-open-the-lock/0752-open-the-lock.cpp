class Solution {
public:
    unordered_map<string,vector<string>> adj;
    unordered_map<string,int> dead;
    
    class Pair {
    public:
        string num;
        int dist;
        
        Pair(int n, string s) {
            this->num = s;
            this->dist = n;
        }
    };
    
    int solve(string src, string target) {
        if(src==target) return 0;
        
        vector<int> dist(10000,INT_MAX);
        queue<Pair*> q;
        Pair* p = new Pair(0,src);
        q.push(p);
        dist[stoi(src)]=0;
        
        while(!q.empty()) {
            Pair* it = q.front(); 
            q.pop();
            
            string cur = it->num;
            int d = it->dist;
            
            // cout << cur << " " << d << endl;
            
            if(cur == target) return d;
            
            for(auto nbr:adj[cur]) {
                if(dist[stoi(nbr)]>d+1) {
                    q.push(new Pair(d+1,nbr));
                    dist[stoi(nbr)] = d+1;
                }
            }
        }
        return -1;
    }
    
    int openLock(vector<string>& deadends, string target) {
        for(auto s:deadends) dead[s]=1;
        
        for(int num=0;num<=9999;num++) {
            string s = to_string(num);
            
            while(s.size()<4) s = "0"+s;
            if(dead.find(s) != dead.end()) continue;
            
            for(int i=0; i<4; i++) {
                string left = s;
                string right = s;
                
                if(left[i] == '0') left[i] = '9';
                else left[i] = left[i]-1;
                
                if(right[i] == '9') right[i] = '0';
                else right[i] = right[i]+1;
                
                adj[s].push_back(left);
                adj[s].push_back(right);
            }
        }
        
        return  solve("0000",target);
    }
};