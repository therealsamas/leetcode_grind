

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        vector<long long> prefsum(nums.size(),0);
        sort(nums.begin(),nums.end());
        prefsum[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            prefsum[i]+= prefsum[i-1] + nums[i];
        }
        long long ans = -1;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]<prefsum[i-1]){
                ans = prefsum[i];
            }else if(nums[i]==prefsum[i-1]){
                continue;
            }
        }
        return ans;
    }
};