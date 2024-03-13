
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hashset;
        for(int i=0; i<wordList.size(); i++){
        	hashset.insert(wordList[i]);
        }
        queue<string> pending;
        pending.push(beginWord);
        unordered_set<string> visited;
        int steps = 1;
        while(!pending.empty()){
        	int len = pending.size();
        	for(int k=0; k<len; k++){
        		string cur = pending.front();
        		pending.pop();
        		for(int i=0; i<cur.size(); i++){
        			char a = cur[i];
        			for(int j=0; j<26; j++){
        				cur[i] = char(j + 97);
        				if(cur==endWord && hashset.find(cur) != hashset.end()){
        					return steps+1;
        				}
        				if(visited.find(cur)==visited.end() && hashset.find(cur) != hashset.end()){
                            visited.insert(cur);
        					pending.push(cur);
        				}
        			}
        			cur[i] = a;
        		}
        	}
            steps++;
        }
        return 0;
    }
};