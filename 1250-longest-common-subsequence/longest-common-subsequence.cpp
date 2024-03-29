class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    	vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,0));
    	for(int i=1; i<=text1.size(); i++){
    		for(int j=1; j<=text2.size(); j++){
				int take = 0;
				if(text1[i-1] == text2[j-1]){
					take = 1 + dp[i-1][j-1];
				}
				int nottake = max(dp[i-1][j],dp[i][j-1]);
				dp[i][j] = max(take,nottake);
    		}
    	}
        return dp[text1.size()][text2.size()];
    }
};