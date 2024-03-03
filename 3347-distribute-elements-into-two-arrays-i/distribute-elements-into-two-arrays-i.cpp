class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2; i<nums.size(); i++){
        	int l1 = arr1.size()-1;
        	int l2 = arr2.size()-1;
        	if(arr1[l1]>arr2[l2]){
        		arr1.push_back(nums[i]);
        	}else{
        		arr2.push_back(nums[i]);
        	}
        }
        for(int i=0; i<arr2.size(); i++){
        	arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};