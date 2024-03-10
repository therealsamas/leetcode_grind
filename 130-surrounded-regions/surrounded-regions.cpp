
class Solution {
public:

	vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
	void dfstrav(vector<vector<char>>& grid, int i, int j){
		grid[i][j] = 'X';
		for(int k=0; k<4; k++){
			int r = i+direction[k][0];
			int c = j+direction[k][1];
			if((r>=0 && r<grid.size()) && (c>=0 && c<grid[0].size()) && grid[r][c]=='O'){
				dfstrav(grid,r,c);
			}
		}
	}

    void solve(vector<vector<char>>& board) {
        vector<vector<char>> grid(board.size(),vector<char>(board[0].size(),'O'));
        for(int i=0; i<board.size(); i++){
        	for(int j=0; j<board[0].size(); j++){
        		grid[i][j] = board[i][j];
        	}
        }
        // visit the boundaries
        for(int i=0; i<grid.size(); i++){
        	if(grid[i][0]=='O'){
        		dfstrav(grid,i,0);
        	}
        	if(grid[i][grid[0].size()-1]=='O'){
        		dfstrav(grid,i,grid[0].size()-1);
        	}
        }
        for(int i=0; i<grid[0].size(); i++){
        	if(grid[0][i]=='O'){
        		dfstrav(grid,0,i);
        	}
        	if(grid[grid.size()-1][i]=='O'){
        		dfstrav(grid,grid.size()-1,i);
        	}
        }

        for(int i=0; i<grid.size(); i++){
        	for(int j=0; j<grid[0].size(); j++){
        		if(grid[i][j]=='O'){
        			dfstrav(board,i,j);
        		}
        	}
        }
    }
};