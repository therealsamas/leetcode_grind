
class Solution {
public:

    bool isValidCoord(int x, int y, vector<vector<int>>& grid){
        return (x>=0 && y>=0 && (x<grid.size()) && (y<grid[0].size()));
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> rottenSourceQueue;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    rottenSourceQueue.push({i,j});
                }
            }
        }
        int timeTaken = 0;
        vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!rottenSourceQueue.empty()){
            int currentSize = rottenSourceQueue.size();
            bool check =0;
            for(int i=0; i<currentSize; i++){
                vector<int> coords = rottenSourceQueue.front();
                rottenSourceQueue.pop();
                for(int k=0; k<4; k++){
                    int x = coords[0] + direction[k][0];
                    int y = coords[1] + direction[k][1];
                    if(isValidCoord(x,y,grid) && grid[x][y] == 1){
                        grid[x][y] = 2;
                        check =1;
                        rottenSourceQueue.push({x,y});
                    }
                }
            }
            if(check){
                timeTaken++;
            }
        }

         for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1; 
                }
            }
        }
        return timeTaken;
    }
};