class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        int i = 0;
        for(i=0; i<heights.size()-1; i++){
            int temp = heights[i+1] - heights[i];
            if(temp>0){
                if(minheap.size()<ladders){
                    minheap.push(temp);
                }else{
                    if(minheap.size()>0 && minheap.top()< temp){
                        bricks-=minheap.top();
                        minheap.pop();
                        minheap.push(temp);
                    }else{
                        bricks-=temp;
                    }
                    if(bricks<0){
                        break;
                    }
                }
            }
        }
        return i;
    }
};