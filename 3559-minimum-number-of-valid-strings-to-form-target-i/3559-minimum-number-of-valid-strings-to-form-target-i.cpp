class Solution {
public:
    class Node {
    public:
        unordered_map<int, Node*> ch;
        bool isEnd = false;
    };

    Node* root;

    Solution() {
        root = new Node();
    }

    void insert(string s) {
        Node* n = root;
        for (char c : s) {
            int idx = c - 'a';
            if (n->ch.find(idx) == n->ch.end()) {
                n->ch[idx] = new Node();
            }
            n = n->ch[idx];
        }
        n->isEnd = true;
    }

    int solve(string& target, int start, int* memo) {
        if (start >= target.size()) return 0;

        if (memo[start] != -1) {
            return memo[start];
        }

        Node* n = root;
        int length = 0;
        int minSplits = 1e7;

        for (int i = start; i < target.size(); ++i) {
            int c = target[i] - 'a';
            if (n->ch.find(c) == n->ch.end()) {
                break;
            }
            n = n->ch[c];
            ++length;
            int splits = 1 + solve(target, start + length, memo);
            minSplits = min(minSplits, splits);
        }
        
        return memo[start] = minSplits;
    }

    int minValidStrings(vector<string>& words, string target) {
        for (const string& word : words) {
            insert(word);
        }
        
        int memo[5005];
        memset(memo,-1,sizeof(memo));
        int result = solve(target, 0, memo);

        return result >= 1e7 ? -1 : result;
    }
};
