class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int left = -1, right = -1, lim = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK){
                lim = i;
            }
            if (nums[i] == minK){
                left = i;
            }
            if (nums[i] == maxK){
                right = i;
            }
            ans += max(0, min(right, left) - lim);
        }
        return ans;
    }
};