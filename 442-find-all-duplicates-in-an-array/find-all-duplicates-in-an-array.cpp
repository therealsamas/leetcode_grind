class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> hashset;
        vector<int> arr;
        for(int i=0; i<nums.size(); i++){
            if(hashset.find(nums[i]) != hashset.end()){
                arr.push_back(nums[i]);
                hashset.erase(nums[i]);
            }
            hashset.insert(nums[i]);
        }
        return arr;
    }
};