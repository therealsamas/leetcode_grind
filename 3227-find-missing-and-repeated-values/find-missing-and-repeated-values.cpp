class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long s1 = (long long)n*n*(n*n+1)/2;
        long long s2 = (long long)n*n*(n*n + 1)*(2*n*n + 1)/6;
        long long totalSum = 0;
        long long totalSquareSum = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                totalSum += grid[i][j];
                totalSquareSum += (long long)grid[i][j] * grid[i][j];
            }
        }

        long long amb = totalSum - s1;
        long long diffSquare = totalSquareSum - s2; 
        long long apb = diffSquare / amb;

        int a = (amb + apb) / 2;
        int b = (apb - amb) / 2; 

        return {a, b}; 
    }
};
