
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> maxheap;

        for(int i=0; i<nums.size(); i++){
            maxheap.push(nums[i]);
        }
        long long score = 0;
        while(k>0){
            int topElement = maxheap.top();
            score += topElement;
            maxheap.pop();
            maxheap.push(ceil((double)topElement/3));
            k--;
        }
        return score;
    }
};