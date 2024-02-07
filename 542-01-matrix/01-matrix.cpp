
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> grid(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> pending;
        for(int i=0; i<mat.size(); i++){
        	for(int j=0; j<mat[0].size(); j++){
        		if(mat[i][j] == 0){
        			pending.push({i,j});
        		}
        	}
        }
        int cur = 1;
       	while(!pending.empty()){
       		int len = pending.size();
       		for(int k=0; k<len; k++){
       			int i = pending.front().first;
       			int j = pending.front().second;
       			pending.pop();
       			for(int l = 0; l<4; l++){
       				int x = i + direction[l][0];
       				int y = j + direction[l][1];
       				if((x>=0 && x<mat.size()) && (y>=0 && y<mat[0].size()) && mat[x][y] == 1){
       					grid[x][y] = cur;
       					mat[x][y] = 0;
       					pending.push({x,y});
       				}
       			}
       		}
       		cur++;
       	}
       	return grid;
    }
};