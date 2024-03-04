class Solution {
public:

	int lpshelper(string& s, string& a, int i, int j, vector<vector<int>>& dp){
		if(i==0 || j==0){
			return 0;
		}
		if(dp[i][j] != -1){
			return dp[i][j];
		}
		if(s[i-1] == a[j-1]){
			return dp[i][j] = lpshelper(s,a,i-1,j-1, dp) + 1;
		}
		return dp[i][j] = max(lpshelper(s,a,i,j-1, dp),lpshelper(s,a,i-1,j, dp));
	}

    int minInsertions(string s) {
        string a = s;
        int n = s.length();
        reverse(a.begin(),a.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return s.length() - lpshelper(s,a,n,n, dp);
    }
};