struct TrieNode {
    bool end;
    TrieNode* next[26];
};

class StreamChecker {
    TrieNode root{};
    string cur;
public:
    StreamChecker(vector<string>& words) {
        for (const auto& w : words) {
            int len = w.length();
            TrieNode* t = &root;
            for (int i = len - 1; i >= 0; --i) {
                char c = w[i] - 'a';
                if (!t->next[c]) {
                    t->next[c] = new TrieNode();
                }
                t = t->next[c];
            }
            t->end = true;
        }
    }
    
    bool query(char letter) {
        cur += letter;
        TrieNode* t = &root;
        for (int i = cur.length() - 1; i >= 0 && t->next[cur[i] - 'a']; --i) {
            t = t->next[cur[i] - 'a'];
            if (t->end) {
                return true;
            }
        }
        return false;
    }
};