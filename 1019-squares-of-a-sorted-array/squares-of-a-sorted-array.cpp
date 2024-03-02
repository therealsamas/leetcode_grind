class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        vector<int> ans(nums.size(),0);
        for(int k=nums.size()-1; k>=0; k--){
            int left = nums[i]*nums[i];
            int right = nums[j]*nums[j];
            if(right>left){
                ans[k] = right;
                j--;
            }else{
                ans[k] = left;
                i++;
            }
        }
        return ans;
    }
};