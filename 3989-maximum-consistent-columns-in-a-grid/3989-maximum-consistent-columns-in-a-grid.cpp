class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid[0].size();
        vector<int> dp(n , 1);
        for(int b = 0 ; b < n ;++b){
            for(int a = 0 ; a < b ; ++a){
                if(dp[a] + 1 > dp[b]){
                    bool ok = true;
                    for(const auto& r : grid){
                        if(abs(r[b] - r[a]) > limit){
                            ok = false;
                            break;
                        }
                    }if(ok){
                        dp[b] = dp[a] + 1;
                    }
                }
            }
        }
        return *max_element(dp.begin() , dp.end());
        
    }
};