class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for(int i=0; i<arr.size(); i++){
            freq[arr[i]]++;
        }
        vector<int> nums;
        unordered_map<int,int>::iterator it;
        for(it = freq.begin(); it != freq.end(); it++){
            nums.push_back(it->second);
        }
        sort(nums.begin(),nums.end());
        int i=0;
        while(k>0 && i<nums.size()){
            if(k<nums[i]){
                break;
            }
            k-=nums[i];
            i++;
        }
        return (nums.size()-i);
    }
};