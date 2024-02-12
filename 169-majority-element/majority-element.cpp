class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int votes=1;
    	int candidate=nums[0];
    	for(int i=1; i<nums.size(); i++){
    		if(nums[i] != candidate){
    			votes--;
    			if(votes==0){
	    			votes=1;
	    			candidate=nums[i];
    			}
    		}else{
    			votes++;
    		}
    	}
    	return candidate;
    }
};