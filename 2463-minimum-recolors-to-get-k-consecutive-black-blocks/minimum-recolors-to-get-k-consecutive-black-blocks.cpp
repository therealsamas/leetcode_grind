class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int currentWhiteBlocks = 0;
        for(int i=0; i<k; i++){
            if(blocks[i]=='W'){
                currentWhiteBlocks++;
            }
        }
        int ans=currentWhiteBlocks;
        for(int i=k; i<blocks.size(); i++){
            if(blocks[i]=='W' && blocks[i-k]=='B'){
                currentWhiteBlocks++;
            }else if(blocks[i]=='B' && currentWhiteBlocks > 0 && blocks[i-k]=='W'){
                currentWhiteBlocks--;
            }
            ans = min(ans,currentWhiteBlocks);
            if(ans==0){
                break;
            }
        }
        return ans;
    }
};