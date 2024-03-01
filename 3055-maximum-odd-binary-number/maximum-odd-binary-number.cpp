class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        string a = "";
        for(int i=0; i<s.size(); i++){
            a+='0';
        }
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1'){
                ones++;
            }
        }
        for(int i=0; i<s.size(); i++){
            if(ones==1){
                break;
            }
            a[i] = '1';
            ones--;
        }
        if(ones==1){
            a[s.size()-1] = '1';
        }
        return a;
    }
};