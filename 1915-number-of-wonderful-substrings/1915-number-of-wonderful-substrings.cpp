class Solution {
public:
    long long wonderfulSubstrings(string s) {
        vector<long long> freq(pow(2,10)+1,0);
        int mask = 0;
        freq[0]=1;
        int n = s.size();
        long long res = 0;
        
        for(int i=0; i<n; i++) {
            if(mask & (1<<(s[i]-'a'))) {
                mask &= (~(1<<(s[i]-'a')));
            } else {
                mask |= (1<<(s[i]-'a'));
            }
            
            res += freq[mask];
            
            for(int j=0; j<10; j++) {
                if(mask & (1<<j)) {
                    // find someeone with exactly that bit not set
                    res += freq[mask&(~(1<<j))];
                } else {
                    // find someone with exactly that bit set 
                    res += freq[mask|(1<<j)];
                }
            }
            
            freq[mask]++;
        }
        
        return res;
    }
};