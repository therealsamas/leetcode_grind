class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int size=1;
        int n = colors.size();
        int ans=0;
        for(int i=1; i<colors.size() +k-1; i++){
            if(colors[i%n] != colors[(i-1)%n]){
                size++;
            }else {
                size=1;
            }
            if(size>=k){
                ans++;
            }
        }
        return ans;
    }
};