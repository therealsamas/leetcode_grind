class Solution {
public:

    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int score = 0;
        int ans = 0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
            }else if(score>0){
                power+=tokens[j];
                score--;
                j--;
            }else{
                break;
            }
            ans = max(score,ans);
        }
        return ans;
    }
};