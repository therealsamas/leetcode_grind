class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        string ans = "";
        for(int i=0; i<order.size(); i++){
            int charind = order[i] - 'a';
            while(freq[charind]>0){
                ans+=order[i];
                freq[charind]--;
            }
        }
        for(int i=0; i<26; i++){
            while(freq[i]>0){
                ans+= char(i + 97);
                freq[i]--;
            }
        }
        return ans;
    }
};