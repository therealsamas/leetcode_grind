class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> hashMap;
        for(int i=0; i<nums1.size(); i++){
            hashMap[nums1[i][0]]+=nums1[i][1];
        }
        for(int j=0; j<nums2.size(); j++){
            hashMap[nums2[j][0]]+=nums2[j][1];
        }
        vector<vector<int>> result;
        unordered_map<int,int>::iterator it;
        for(it=hashMap.begin(); it != hashMap.end(); it++){
            result.push_back({it->first,it->second});
        }
        sort(result.begin(),result.end());
        return result;
    }
};