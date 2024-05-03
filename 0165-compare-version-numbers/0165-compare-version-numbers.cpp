class Solution {
public:

    bool cmp(string s1, string s2){
        if(s1.size() == s2.size()){
            return s1 > s2;
        }
        return s1.size() > s2.size();
    }

    int compareVersion(string v1, string v2) {
        int n = v1.size();
        int m = v2.size();

        for(int i=0, j=0; i<n || j<m ; i++,j++){
            string s1 = "";
            string s2 = "";

            while(i<n && v1[i] != '.'){
                if(s1.size() == 0 && v1[i] == '0'){
                    i++;
                }else{
                    s1 += v1[i++];
                }
            }
            while(j<m && v2[j] != '.'){
                if(s2.size() == 0 && v2[j] == '0'){
                    j++;
                }else{
                    s2 += v2[j++];
                }
            }

            if(cmp(s1, s2))return 1;
            if(cmp(s2, s1))return -1;
        }
        return 0;
    }
};