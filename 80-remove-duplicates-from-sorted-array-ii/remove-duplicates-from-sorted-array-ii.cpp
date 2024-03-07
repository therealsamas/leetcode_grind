class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        int count = 0;
        int prev = 10e5;
        while(i<nums.size()){
        	if(nums[i]==prev){
        		if(count<2){
	        		nums[j] = nums[i];
	        		count++;
	                j++;
        		}
        	}else{
        		nums[j] = nums[i];
        		count = 1;
        		prev = nums[i];
                j++;
        	}
            i++;
        }
        return j;
    }
};