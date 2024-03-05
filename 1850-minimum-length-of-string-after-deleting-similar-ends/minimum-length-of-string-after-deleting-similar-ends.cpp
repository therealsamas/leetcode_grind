class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                char a = s[i];
                while(i<=j && s[i]==a){
                    i++;
                }
                while(i<=j && s[j]==a){
                    j--;
                }
            }else{
                break;
            }
        }
        if(i>j){
            return 0;
        }
        return (j-i + 1);
    }
};