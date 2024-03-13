
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indeg(numCourses,0);
        queue<int> pending;
        vector<vector<int>> adjlist(numCourses,vector<int>());
        for(int i=0; i<prerequisites.size(); i++){
        	adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0; i<adjlist.size(); i++){
        	for(int j=0; j<adjlist[i].size(); j++){
        		indeg[adjlist[i][j]]++;
        	}
        }
        for(int i=0; i<numCourses; i++){
            cout<<indeg[i]<<endl;
        	if(indeg[i]==0){
        		pending.push(i);
        	}
        }
        while(!pending.empty()){
        	int len = pending.size();
        	for(int k=0; k<pending.size(); k++){
        		int cur = pending.front();
        		pending.pop();
        		ans.push_back(cur);
        		for(int i=0; i<adjlist[cur].size(); i++){
        			indeg[adjlist[cur][i]]--;
        			if(indeg[adjlist[cur][i]]==0){
        				pending.push(adjlist[cur][i]);
        			}
        		}
        	}
        }
        return (numCourses==ans.size());
    }
};