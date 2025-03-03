class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> lt;
        queue<int> eq;
        queue<int> gt;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < pivot){
                lt.push(nums[i]);
            }else if(nums[i] == pivot){
                eq.push(nums[i]);
            }else{
                gt.push(nums[i]);
            }
        }
        vector<int> ans;
        while(!lt.empty()){
            ans.push_back(lt.front());
            lt.pop();
        }    
        while(!eq.empty()){
            ans.push_back(eq.front());
            eq.pop();
        }
        while(!gt.empty()){
            ans.push_back(gt.front());
            gt.pop();
        }   
        
        return ans;
    }
};