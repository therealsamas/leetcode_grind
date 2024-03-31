class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele = 0;
        // get maxele
        for(int i=0; i<nums.size(); i++){
            maxele = max(maxele,nums[i]);
        }
        int freq =0;
        long long ans = 0;
        int left = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==maxele){
                freq++;
            }
            while(freq>=k){
                if(nums[left]==maxele){
                    freq--;
                }
                left++;
            }
            ans+= (left);
        }
        return ans;
    }
};
