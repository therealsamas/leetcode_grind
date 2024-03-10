class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        vector<int> ans;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                if(ans.size()==0 || (ans.size()>0 && ans[ans.size()-1] != nums1[i])){
                    ans.push_back(nums1[i]);
                    i++,j++;
                    continue;
                }
            }
            if(nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};