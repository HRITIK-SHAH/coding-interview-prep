class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j  < n ; j++){
                long long g = std::gcd(nums[i], nums[j]);
                long long strength = (1LL * nums[i] / g) * (nums[j] / g);
                answer = max(answer , strength);
            }
        }
        return answer;
        
    }
};