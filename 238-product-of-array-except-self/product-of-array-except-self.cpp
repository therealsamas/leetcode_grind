class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size(),1),suff(nums.size(),1);
        pref[0] = nums[0];
        suff[nums.size()-1] = nums[nums.size()-1];
        for(int i=1; i<nums.size(); i++){
            pref[i] = nums[i]*pref[i-1];
            int j = nums.size()-i-1;
            suff[j] = nums[j]*suff[j+1];
        }
        vector<int> ans;
        ans.push_back(suff[1]);
        for(int i=1; i<nums.size()-1; i++){
            ans.push_back(pref[i-1]*suff[i+1]);
        }
        ans.push_back(pref[nums.size()-2]);
        return ans;
    }
};
