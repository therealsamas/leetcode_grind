class Solution {
public:

    bool ispalindrome(string& s){
        int i,j;
        if(s.size() % 2 == 0){
            j = s.size()/2;
            i = j-1;
        }else{
            j = s.size()/2;
            i=j;
        }
        while(i>=0 && j<s.size()){
            if(s[i] != s[j]){
                return 0;
            }
            i--;
            j++;
        }
        return 1;

    }

    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            if(ispalindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};