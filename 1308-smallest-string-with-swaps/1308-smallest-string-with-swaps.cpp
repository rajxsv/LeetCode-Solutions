class DSU {
private:
    vector<long long> parent, size;

public:
    DSU(int s) {
        parent.resize(s);
        size.resize(s);
        
        for(int i=0; i<s; i++) {
            parent[i] = i;
            size[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSize(int x, int y) {
        int parx = find(x);
        int pary = find(y);    

        if(parx == pary) return;
        
        if(size[parx] >= size[pary]) {
            parent[pary] = parx;
            size[parx] += size[pary];
        } else {
            parent[parx] = pary;
            size[pary] += size[parx];
        }
    }

};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        string res(n, ' ');
        unordered_map<int,vector<int>> components;
        DSU dsu(n);

        for(auto it : pairs) {
            int a = it[0];
            int b = it[1];

            dsu.unionSize(a,b);
        }

        for(int i=0; i<n; i++) {
            components[dsu.find(i)].push_back(i);
        }

        for(auto it : components) {
            vector<char> chars;
            vector<int> indexes = it.second;
            
            for(auto it2 : it.second) {
                chars.push_back(s[it2]);
            }
            sort(begin(chars), end(chars));


            for(int ind = 0; ind < chars.size(); ind++) {
                res[indexes[ind]] = chars[ind];
            }
        }

        return res;
    }
};