class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int bitSize =nums[0].length();
        int maxNum = 1 << bitSize;
        unordered_set<int> numsSet;

        for(string& num : nums)
        numsSet.insert(stoi(num , nullptr , 2));

        for(int num = 0 ; num < maxNum ; ++num)
        if(!numsSet.contains(num))
        return std::bitset<16>(num).to_string().substr(16 -bitSize);

        throw;
        
    }
};