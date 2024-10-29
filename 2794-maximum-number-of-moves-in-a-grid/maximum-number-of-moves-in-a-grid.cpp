class Solution {
public:  
    int minHelper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    	if(j+1 == grid[0].size()){
    		return 0;
    	}
    	if(dp[i][j] != -1){
    		return dp[i][j];
    	}
        int cur = grid[i][j];
        int a = (i!=0 && cur<grid[i-1][j+1]) ? (minHelper(grid,i-1,j+1,dp)) + 1 : 0;
        int b = (cur < grid[i][j+1]) ? (minHelper(grid,i,j+1,dp)) + 1 : 0;
        int c = (i!=grid.size()-1 && cur<grid[i+1][j+1]) ? (minHelper(grid,i+1,j+1,dp)) + 1 : 0;
        return dp[i][j] = max(max(a,b),c);
    }

    int maxMoves(vector<vector<int>>& grid) {
        int globMax = 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0; i<grid.size(); i++){
        	globMax = max(minHelper(grid,i,0,dp),globMax);
        }
        return globMax;
    }
};