class Solution {
public:

    int globMin = INT_MAX;

    void solveHelper(vector<vector<int>>& grid, int steps){
        bool zeroExists = false;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    zeroExists = true;
                    for(int x=0; x<grid.size(); x++){
                        for(int y=0; y<grid[0].size(); y++){
                            if(grid[x][y] > 1){
                                grid[x][y]--;
                                grid[i][j]++;
                                int curstep = (abs(i-x) + abs(j-y));
                                steps+= curstep;
                                solveHelper(grid, steps);
                                // restore
                                steps-=curstep;
                                grid[x][y]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        if(!zeroExists){
            globMin = min(globMin,steps);
        }
    }

    int minimumMoves(vector<vector<int>>& grid) {
        solveHelper(grid,0);
        return globMin;
    }
};