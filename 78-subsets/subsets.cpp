class Solution {
public:
	vector<vector<int>> ans;
	vector<int> temp;
	void subsetgen(vector<int>& nums,int index){
		if(index==nums.size()){
			ans.push_back(temp);
			return;
		}
		// not include
		subsetgen(nums,index+1);
		// include
		temp.push_back(nums[index]);
		subsetgen(nums,index+1);
		temp.pop_back();
	}
    vector<vector<int>> subsets(vector<int>& nums) {
    	subsetgen(nums,0);
        return ans;
    }
};