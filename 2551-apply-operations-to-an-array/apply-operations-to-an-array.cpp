class Solution {
public:

    void bubbleSortZeros(vector<int>& nums){
        for(int i=0; i<nums.size()-1; i++){
            for(int j=0; j<nums.size()-i-1; j++){
                if (nums[j] == 0){
                    nums[j] = nums[j+1];
                    nums[j+1] = 0;
                }
            }
        }
    }

    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }
        bubbleSortZeros(nums);
        return nums;
    }
};