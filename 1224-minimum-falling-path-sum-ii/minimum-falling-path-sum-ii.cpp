class Solution {
public:

    int pathsumhelper(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp){
        if(r==grid.size()){
            return 0;
        }
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        int ans = INT_MAX;
        for(int i=0; i<grid[r].size(); i++){
            if(c==i){
                continue;
            }
            ans = min(ans,grid[r][i] + pathsumhelper(grid,r+1,i,dp));
        }
        return dp[r][c] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        if(grid.size()==1){
            for(int i=0; i<grid[0].size(); i++){
                ans = min(ans,grid[0][i]);
            }
            return ans;
        }
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        for(int i=0; i<grid.size(); i++){
            ans = min(ans,pathsumhelper(grid,0,i,dp));
        }
        return ans;
    }
};