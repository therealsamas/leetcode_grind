
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]>0){
                break;
            }
            int k = abs(nums[l]);
            if(k==nums[r]){
                return k;
            }else if(k>nums[r]){
                l++;
            }else{
                r--;
            }
        }
        return -1;
    }
};