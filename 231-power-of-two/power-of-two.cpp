
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return 0;
        }
        int i = 1;
        while(i<32 && (1<<i)<n){
            if(n&(1<<i)){
                return 0;
            }
            i++;
        }
        return 1;
    }
};