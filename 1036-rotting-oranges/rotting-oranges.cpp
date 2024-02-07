
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> pending;
        vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0; i<grid.size(); i++){
        	for(int j=0; j<grid[0].size(); j++){
        		if(grid[i][j] == 2){
        			pending.push({i,j});
        		}
        	}
        }
        int time = 0;
        while(!pending.empty()){
        	int len = pending.size();
        	bool check =0;
        	for(int k=0; k<len; k++){
        		int i = pending.front().first;
        		int j = pending.front().second;
        		pending.pop();
        		for(int l=0; l<4; l++){
        			int x = i + direction[l][0];
        			int y = j + direction[l][1];
        			if((x>=0 && x<grid.size()) && (y>=0 && y<grid[0].size()) && grid[x][y] == 1){
        				grid[x][y] = 2;
        				check = 1;
        				pending.push({x,y});
        			}
        		}
        	}
        	if(check){
        		time++;
        	}
        }
        for(int i=0; i<grid.size(); i++){
        	for(int j=0; j<grid[0].size(); j++){
        		if(grid[i][j] == 1){
        			return -1;
        		}
        	}
        }
        return time;
    }
};