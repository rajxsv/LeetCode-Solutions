class Solution {
public:
    int n,m;

    bool replace(string s, string t) {
        int i = 0, j = 0, f = 0;

        while(i<n) {
            cout << "comparing " << s[i] << "  " << s[j] << "with f = " << f << endl;
            if(s[i] != t[j]) {
                if(f) return false;
                f = 1;
            }
            i++; 
            j++;
        }

        return true;
    }

    bool deleteOrInsert(string s, string t) {
        int i = 0, j = 0, f = 0;

        while(i < s.size() && j < t.size()) {
            if(s[i] != t[j]) {
                if(f) return false;
                f = 1;
                j--;
            }
            i++; 
            j++;
        }

        return true;
    }

    bool isOneEditDistance(string s, string t) {
        // replace
        n = s.size();
        m = t.size();

        if(abs(n - m) > 1 || s == t) return false;

        if(n == m) {
            return replace(s,t);
        } else if(n > m) {
            return deleteOrInsert(s,t);
        }

        return deleteOrInsert(t,s);
    }
};