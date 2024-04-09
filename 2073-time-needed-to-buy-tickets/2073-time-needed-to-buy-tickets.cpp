class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int n=t.size();
        int time=0;
        int size=n;
        int right=0;
        
        for(int i=k+1;i<n;i++) {
            if(t[i]>=t[k]) right++;
        }
        
        for(int j=0;j<=n;j++) {
            int mn=INT_MAX;
            int sizeDec=0;
            
            for(int i=0;i<n;i++){
                if(t[i]!=-1) mn=min(mn,t[i]);
            }
            
            time+=size*mn;
            for(int i=0;i<n;i++){
                if(t[i]!=-1) {
                    if(t[i]==mn) sizeDec++;
                    t[i]-=mn;    
                }
                
                if(t[i]==0) t[i]=-1;
            } 
            size -= sizeDec;
            if(t[k]==-1) return time-right;
             
        }
        
        return 0;
    }
};