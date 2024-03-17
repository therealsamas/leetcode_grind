class Solution {
public:
    int minimumDeletions(string word, int k) {
    	vector<int> freq(26,0);
    	for(int i=0; i<word.size(); i++){
    		freq[(word[i]-'a')]++;
    	}
    	sort(freq.begin(),freq.end());
    	int ans = INT_MAX;
    	for(int i=0; i<26; i++){
    		int count = 0;
            if(freq[i]==0){
                continue;
            }
    		for(int j=0; j<26; j++){
    			if(i==j){
    				continue;
    			}
    			if(freq[i]+k<freq[j]){
    				count+= (freq[j] - (freq[i]+k));
    			}else if(freq[i]>freq[j]){
    				count+=freq[j];
    			}
    			if(count>ans){
    				break;
    			}
    		}
    		ans = min(ans,count);
    	}
    	return ans;
    }
};
