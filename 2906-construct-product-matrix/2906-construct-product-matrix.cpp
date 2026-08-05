class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
       int kMod = 12345;
       int m = grid.size();
       int n = grid[0].size();

       vector<vector<int>> ans(m , vector<int>(n));
       vector<int> prefix{1};
       int suffix = 1;

       for(vector<int>& row : grid)
       for(int num : row)
       prefix.push_back(static_cast<long>(prefix.back()) * num %kMod);

       for(int i = m - 1; i >= 0 ; --i)
       for(int j = n - 1; j >= 0 ; --j){
        ans[i][j] = prefix[ i * n + j] * suffix % kMod;
        suffix = static_cast<long>(suffix) * grid[i][j] % kMod;
       } 
       return ans;
    }
};