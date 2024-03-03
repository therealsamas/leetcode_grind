class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
    	int ans= 0;
    	for(int i=0; i<grid.size(); i++){
    		for(int j=0; j<grid[0].size(); j++){
    			int temp = 0;
    			if(i-1>=0){
    				temp += grid[i-1][j];
    			}
    			if(j-1>=0){
    				temp += grid[i][j-1];
    			}
    			if(i-1>=0 && j-1>=0){
    				temp-= grid[i-1][j-1];
    			}
    			grid[i][j] += temp;
                // cout<<grid[i][j]<<endl;
    			if(grid[i][j]<=k){
    				ans++;
    			}
    		}
    	}
    	return ans;
    }
};