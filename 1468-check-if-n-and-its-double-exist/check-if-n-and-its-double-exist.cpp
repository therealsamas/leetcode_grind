
class Solution {
public:

    bool binsearch(vector<int>& arr, int idx){
        int lo=0;
        int hi = arr.size()-1;
        int val = 2*arr[idx];
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid] == val && idx != mid){
                return true;
            }else if(arr[mid] < val){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return false;
    }

    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++){
            if(binsearch(arr,i)){
                return true;
            }
        }
        return false;
    }
};