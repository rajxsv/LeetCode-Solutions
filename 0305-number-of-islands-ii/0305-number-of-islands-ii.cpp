class DSU {
private:
    vector<int> parent, rank;
    int count;

public:
    DSU(int size) {
        parent.resize(size,-1);
        rank.resize(size,0);
        count=0;
    }

    void addLand(int x) {
        if(parent[x]>=0) return;
        parent[x]=x;
        count++;
    }

    bool isLand(int x) {
        if(parent[x]>=0) return true;
        return false;
    }

    int numberOfIslands() {
        return count;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return find(parent[x]);
    }

    void unionSize(int x, int y) {
        int parX = find(x);
        int parY = find(y);

        if(parX == parY) return;

        if(rank[parX]>rank[parY]) {
            parent[parY] = parX;
        } else if (rank[parY]>rank[parX]) {
            parent[parX] = parY;
        } else {
            parent[parX] = parY;
            rank[parX]++;
        }
        count--;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int x[] = {-1, 1, 0, 0};
        int y[] = {0, 0, -1, 1};
        DSU dsu(m*n);
        vector<int> ans;

        for(auto &p:positions) {
            int landPos = p[0]*n + p[1];
            dsu.addLand(landPos);

            for(int i=0; i<4; i++) {
                int nx = p[0] + x[i];
                int ny = p[1] + y[i];

                int nPos = nx*n + ny;

                if(nx>=0 && nx<m && ny>=0 && ny<n && dsu.isLand(nPos)) {
                    dsu.unionSize(landPos, nPos);
                }
            }
            ans.push_back(dsu.numberOfIslands());
        }
        return ans;
    }
};