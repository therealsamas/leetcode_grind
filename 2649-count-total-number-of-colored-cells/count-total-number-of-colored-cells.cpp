class Solution {
public:
    long long coloredCells(int n) {
        long long prev = 1;
        long long ans = 1;
        for(int i=1; i<=n; i++){
            ans = 4*(i-1) + prev;
            prev = ans;
        }
        return ans;
    }
};