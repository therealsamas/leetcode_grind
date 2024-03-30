class Solution {
public:
    int counthelper(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;      
        int unicount = 0;
        int ans = 0;
        int prev=0;
        for(int i=0; i<nums.size(); i++){
            if(hashmap[nums[i]]==0){
                unicount++;
            }
            hashmap[nums[i]]++;
            while(unicount>k){
                hashmap[nums[prev]]--;
                if(hashmap[nums[prev]]==0){
                    unicount--;
                }
                prev++;
            }
            ans+=(i-prev+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return counthelper(nums, k) - counthelper(nums, k-1);
    }
};