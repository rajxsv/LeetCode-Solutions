class Solution {
public:
    
    bool isValid(string t) {
        // cout << t << " ";
        if(t[0]=='0' || t[0]=='1') {  // 59
            if(t[1]>='0' && t[1]<='9' && (t[3]>='0'&&t[3]<='5'&&t[4]>='0'&&t[4]<='9')) return true;
            return false;
        }
        else if(t[0]=='2' && t[1]>='0' && t[1]<='3' && t[3]>='0'&&t[3]<='5'&&t[4]>='0'&&t[4]<='9') return true;
        return false;
    }
    
    string latestTime(string s1,string s2) {
        if(s1=="") return s2;
        // cout << s1+","+s2 << endl;
        for(int i=0;i<s2.size();i++) {
            if(s1[i]>s2[i]) return s1;
            else if(s2[i]>s1[i]) return s2;
        }
        return s1;
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        int n=4;
        string res="";
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++) {
                    for(int l=0;l<n;l++) {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        string time=to_string(arr[i])+to_string(arr[j])+":"+to_string(arr[k])+to_string(arr[l]);
                        
                        if(isValid(time)) {
                            res = latestTime(res,time);
                        }
                    }
                    
                }
            }
        }
        return res;
    }
};