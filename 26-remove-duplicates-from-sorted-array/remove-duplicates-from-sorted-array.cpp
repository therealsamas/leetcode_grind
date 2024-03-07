class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> hashset;
        for(int i=0; i<nums.size(); i++){
        	if(hashset.find(nums[i]) == hashset.end()){
        		hashset.insert(nums[i]);
        	}
        }
        nums.clear();
        nums = {hashset.begin(),hashset.end()};
        return hashset.size();
    }
};