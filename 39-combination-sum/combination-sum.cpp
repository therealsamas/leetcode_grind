class Solution {
public:
	vector<vector<int>> ans;
	void combinehelper(vector<int>& candidates, int target, int index, vector<int>& temp){
		if(target==0 || index==candidates.size()){
			if(target==0){
				ans.push_back(temp);
			}
			return;
		}
		if(candidates[index]<=target){
			temp.push_back(candidates[index]);
			combinehelper(candidates,target - candidates[index], index, temp);
			temp.pop_back();
		}
		combinehelper(candidates,target,index+1,temp);
		return;
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	sort(candidates.begin(), candidates.end());
    	vector<int> temp;
    	combinehelper(candidates,target,0,temp);
    	return ans;
    }
};