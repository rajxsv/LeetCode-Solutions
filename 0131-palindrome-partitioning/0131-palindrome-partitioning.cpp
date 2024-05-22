class Solution {
public:
    
    vector<vector<string>> res;
    
    bool isPalindrome(string s) {
        int i=0;
        for(int i=0; i<s.size()/2; i++) {
            if(s[i]!=s[s.size()-1-i]) {
                return false;
            }
        }
        return true;
    }
    
    void solve(string s, int ind, vector<string> cur) {
        if(ind>=s.size()) {
            res.push_back(cur);
            return;
        }
        
        for(int i=ind; i<s.size(); i++) {
            string test = s.substr(ind,(i-ind+1));
            if(isPalindrome(test)) {
                cur.push_back(test);
                solve(s,i+1,cur);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        solve(s,0,{});
        return res;
    }
};