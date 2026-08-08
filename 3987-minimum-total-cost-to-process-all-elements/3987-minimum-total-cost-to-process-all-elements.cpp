class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long ops = 0 , res = k;

        for(long long x : nums){
            if(res < x){
                long long add = ( x - res + k - 1)/ k;
                ops += add;
                res += add * k;
            }
            res -= x ;
        }
        const long long MOD = 1e9 +  7;

        if(ops % 2 == 0){
            return ((ops / 2 ) % MOD) * ((ops + 1) % MOD) % MOD;


        }
        return (ops % MOD ) * (((ops + 1 ) / 2) % MOD) %MOD;
    }
};