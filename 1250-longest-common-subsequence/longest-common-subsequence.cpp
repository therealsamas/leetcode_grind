class Solution {
public:
	int numsqhelper(string& s, string& t, int i, int j, vector<vector<int>>& dp){
		if(i==0 || j==0){
			return 0;
		}
		if(dp[i][j] != -1){
			return dp[i][j];
		}
		int take = 0;
		if(s[i-1] == t[j-1]){
			take = 1 + numsqhelper(s,t,i-1,j-1, dp);
		}
		int nottake = max(numsqhelper(s,t,i-1,j, dp), numsqhelper(s,t,i,j-1, dp));
		return dp[i][j] = max(take,nottake);
	}

    int longestCommonSubsequence(string text1, string text2) {
    	vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,-1));
        return numsqhelper(text1,text2,text1.size(),text2.size(), dp);
    }
};