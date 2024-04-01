class Solution {
public:
    int lengthOfLastWord(string s) {
        int count =0;
        bool a=0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==' '){
                if(a){
                    break;
                }
                continue;
            }else{
                count++;
                a=1;
            }
        }      
        return count;
    }
};