
class Solution {
public:
	vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
	void dfs(vector<vector<int>>& grid, int i, int j){
		grid[i][j] = 2;
		for(int k=0; k<4; k++){
			int x = i + direction[k][0];
			int y = j + direction[k][1];
			if((x>=0 && x<grid.size()) && (y>=0 && y<grid[0].size()) && grid[x][y] == 0){
				dfs(grid,x,y);
			}
		}
	}
    int closedIsland(vector<vector<int>>& grid) {
    	int n = grid.size();
    	int m = grid[0].size();
    	for(int i=0; i<n; i++){
    		if(grid[i][0] == 0){
    			dfs(grid,i,0);
    		}
    		if(grid[i][m-1] == 0){
    			dfs(grid,i,m-1);
    		}
    	}
    	for(int i=0; i<m; i++){
    		if(grid[0][i]==0){
    			dfs(grid,0,i);
    		}
    		if(grid[n-1][i]==0){
    			dfs(grid,n-1,i);
    		}
    	}
    	int ans = 0;
    	for(int i=1; i<n-1; i++){
    		for(int j=1; j<m-1; j++){
    			if(grid[i][j]==0){
    				dfs(grid,i,j);
    				ans++;
    			}
    		}
    	}
    	return ans;
    }
};