class Solution {
public:
    int maximumSwap(int num) {
        string numStr=to_string(num);
        int n=numStr.size();
        int maxDigit=-1;
        int maxDigitIndex=-1;

        string copy=numStr;
        sort(begin(copy),end(copy));

        for(int i=n-1;i>=0;i--){
            if(numStr[n-i-1]!=copy[i]){
                maxDigit=copy[i]-'0';
                break;
            }
        }

        for(int i=0;i<n;i++){
            if(numStr[i]-'0'==maxDigit){
                maxDigitIndex=i;
            }
        }

        for (int i=0;i<n;i++) {
            if (numStr[i]-'0'<maxDigit && maxDigitIndex>i) {
                swap(numStr[i],numStr[maxDigitIndex]);
                break;
            }
        }
        
        return stoi(numStr);
    }
};