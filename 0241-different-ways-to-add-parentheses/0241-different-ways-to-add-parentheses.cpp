class Solution {
public:
    
    int compute(int a, int b, char op) {
        if(op=='+') return a+b;
        if(op=='-') return a-b;
        return a*b;
    }
    
    vector<int> diffWaysToCompute(string exp) {
        int n=exp.size();
        int f=1;
        vector<int> res;
        for(int i=0;i<n;i++) {
            if(!isdigit(exp[i])) {
                f=0;
                vector<int> left=diffWaysToCompute(exp.substr(0,i));
                vector<int> right=diffWaysToCompute(exp.substr(i+1));
                
                for(auto a:left) {
                    for(auto b:right) {
                        res.push_back(compute(a,b,exp[i]));
                    }
                }
            }
        }
        if(f) res.push_back(stoi(exp));
        return res;
    }
};