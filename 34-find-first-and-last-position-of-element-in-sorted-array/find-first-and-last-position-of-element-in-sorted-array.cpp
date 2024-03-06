
class Solution {
public:
	int lower_bound(vector<int>& nums, int target){
		int lo = 0, hi = nums.size()-1;
		while(lo<=hi){
			int mid = lo + (hi-lo)/2;
			if(nums[mid]>=target){
				hi = mid-1;
			}else{
				lo = mid+1;
			}
		}
		if(lo>=nums.size() || nums[lo] != target){
			return -1;
		}
		return lo;
	}
	int upper_bound(vector<int>& nums, int target){
		int lo = 0, hi = nums.size()-1;
		while(lo<=hi){
			int mid = lo + (hi-lo)/2;
			if(nums[mid]>target){
				hi = mid-1;
			}else{
				lo = mid+1;
			}
		}
		if(hi<0 || nums[hi] != target){
			return -1;
		}
		return hi;
	}

    vector<int> searchRange(vector<int>& nums, int target) {
    	return {lower_bound(nums,target),upper_bound(nums,target)};
    }
};