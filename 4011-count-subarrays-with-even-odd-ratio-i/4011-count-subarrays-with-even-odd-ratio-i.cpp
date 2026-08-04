class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int answer = 0 ;

        for(int left = 0 ; left < n ; left++){
            int evenCount = 0;
            int oddCount = 0;

            for(int right = left; right < n ; right++){
                if(nums[right] & 1)
                    oddCount++;
                else
                    evenCount++;

                if(oddCount > 0 && 1LL * evenCount * b <= 1LL * oddCount * a)
                    answer++;
            }
        }
        return answer;
    }
};