class Solution {
public:

    long long calchelper(int n){
        if(n<=1){
            return 1;
        }

        long long ans = 4*(n-1) + calchelper(n-1);
        return ans;
    }

    long long coloredCells(int n) {
        return calchelper(n);
    }
};