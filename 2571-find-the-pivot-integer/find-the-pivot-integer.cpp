class Solution {
public:
    int pivotInteger(int n) {
        int lo = 1;
        int hi = n;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int split1 = ((mid)*(mid+1))/2;
            int split2 = ((n)*(n+1))/2 - split1 + mid;
            if(split1==split2){
                return mid;
            }else if(split1<(split2)){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return -1;
    }
};