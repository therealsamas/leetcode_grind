
class Solution {
public:
    int row, col;
    int counthelper(int r, int c0, int c1, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if (r>=row || c0<0 || c0>=col || c1<0 || c1>=col){
            return 0;
        }
        if (dp[r][c0][c1]!=-1){
            return dp[r][c0][c1];
        }
        int ans=(c0!=c1)?grid[r][c0]+grid[r][c1]:grid[r][c0];
        int next=0;
        for (int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                next=max(next, counthelper(r+1, c0+i-1, c1+j-1, grid,dp));
            }
        }
        ans+=next;
        return dp[r][c0][c1]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        row=grid.size(), col=grid[0].size();
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return counthelper(0, 0, col-1, grid,dp);
    }
};
