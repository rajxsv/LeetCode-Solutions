class Solution {
public:

    bool isPrime(int a) { 
        if (a==1) {
            return 0;
        } 
        for (int i = 2; i <= round(sqrt(a)); i++) {
            if (a%i==0) {
                return 0;
            } 
        }
        return 1; 
    }

    void fillPrimes(int num, vector<int> &primesSmaller) {
        for(int i=2; i<num; i++) {
            if(isPrime(i)) {
                primesSmaller.push_back(i);
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            vector<int> primesSmaller;
            fillPrimes(nums[i],primesSmaller);
            int prev = (i == 0 ? 0 : nums[i-1]);
            int f = 1;

            for(int j = primesSmaller.size() - 1; j >= 0; j--) {
                if(nums[i] - primesSmaller[j] > prev) {
                    nums[i] -= primesSmaller[j];
                    f = 0;
                    break;
                }
            }
            if(f && i!=0 && nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
};