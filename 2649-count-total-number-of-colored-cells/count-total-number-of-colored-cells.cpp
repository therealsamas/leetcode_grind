class Solution {
public:

    long long calchelper(int n, vector<long long>& dp){
        if(n<=1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = 4*(n-1) + calchelper(n-1,dp);
        return dp[n];
    }

    long long coloredCells(int n) {
        vector<long long> dp(n+1,-1);
        return calchelper(n,dp);
    }
};