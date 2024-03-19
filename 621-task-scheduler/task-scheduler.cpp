
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i=0; i<tasks.size(); i++){
            freq[tasks[i] - 'A']++;
        }
        int ans = 0;
        priority_queue<int> maxheap;
        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                maxheap.push(freq[i]);
            }
        }
        while(!maxheap.empty()){
            vector<int> temp;
            int count=0;
            for(int i=0; i<=n; i++){
                if(maxheap.empty()){
                    break;
                }
                int cur = maxheap.top();
                if(cur > 1){
                    cur--;
                    temp.push_back(cur);
                }
                maxheap.pop();
                count++;
            }
            for(int i=0; i<temp.size(); i++){
                maxheap.push(temp[i]);
            }
            if(maxheap.empty()){
                ans+=count;
            }else{
                ans+=n+1;
            }

        }
        return ans;
    }
};