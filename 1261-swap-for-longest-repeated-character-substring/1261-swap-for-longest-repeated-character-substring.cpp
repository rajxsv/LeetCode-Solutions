class Solution {
public:
    int maxRepOpt1(string t) {
        vector<int> freq(26,0);
        int n = t.size();
        int ans = 0;

        for(auto ch : t) {
            freq[ch-'a']++;
        }
        for(char c='a'; c<='z'; c++) {
            int streak = 0;
            int f = 0;
            int maxStreak = 0;
            int maxf = 0;
            int streakStart = 0;

            for(int i=0; i<n; i++) {
                if(streak == 1) streakStart = i-1;
                if(t[i] == c) {
                    streak++;
                } else if(f == 0) {
                    f = 1;
                    streak++;
                } else {
                    f = 0;
                    streak = 0;
                    i = streakStart;
                }
                if(streak>maxStreak) {
                    maxf = f;
                    maxStreak = streak;
                }
            }

            int cnt = maxStreak-maxf;
             
            if(cnt < freq[c-'a']) {
                if(maxf) {
                    ans = max(ans,maxStreak);
                } 
            } else {
                if(maxf) {
                    ans = max(ans,maxStreak-1);
                } else {
                    ans = max(ans,maxStreak);
                }
            }
        }
        return ans;
    }
};