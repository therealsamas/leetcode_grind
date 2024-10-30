
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
    	vector<int> left(nums.size(),1);
    	vector<int> right(nums.size(),1);
    	for(int i=1; i<nums.size(); i++){
    		for(int j=0; j<i; j++){
    			if(nums[i]>nums[j] && left[i] < left[j] + 1){
    				left[i] = left[j] + 1;
    			}
    			int a = nums.size()-1 -i;
    			int b = nums.size()-1 -j;
    			if(a<b && nums[a]>nums[b] && right[a] < right[b] + 1){
    				right[a] = right[b]  + 1;
    			}
    		}
    	}
    	int ans = 1;
    	for(int i=0; i<nums.size(); i++){
				if(left[i]!=1 && right[i]!=1){
    		ans = max(ans, left[i] + right[i] - 1);
				}
    	}
    	return nums.size() - ans;
    }
};