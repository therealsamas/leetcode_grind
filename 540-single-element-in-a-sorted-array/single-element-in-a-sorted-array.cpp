class Solution {
public:
	int binsearch(vector<int>& nums){
		int lo = 1,hi = nums.size()-2;
		while(lo<=hi){
			int mid = lo + (hi - lo)/2;
			if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
				return nums[mid];
			}
			if(mid%2==0){
				if(nums[mid]==nums[mid+1]){
					lo = mid+1;
				}else{
					hi = mid-1;
				}
			}else{
				if(nums[mid]==nums[mid-1]){
					lo=mid+1;
				}else{
					hi = mid-1;
				}
			}
		}
		return -1;
	}
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
        	return nums[0];
        }
        if(nums[0] != nums[1]){
        	return nums[0];
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
        	return nums[nums.size()-1];
        }
        return binsearch(nums);
    }
};