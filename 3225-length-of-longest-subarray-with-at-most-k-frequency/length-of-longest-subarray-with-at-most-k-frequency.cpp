class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        int prev=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            // cout<<prev<<" "<<i<<endl;
            int cur = nums[i];
            hashmap[cur]++;
            while(hashmap[cur]>k){
                hashmap[nums[prev]]--;
                prev++;
                if(prev==i){
                    break;
                }
            }
            ans = max(ans,i-prev + 1);
        }
        return ans;
    }
};