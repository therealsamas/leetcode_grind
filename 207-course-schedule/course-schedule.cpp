
class Solution {
public:

	bool dfstrav(int cur, vector<bool>& visited, vector<bool>& pathvisit, vector<vector<int>>& adjlist){
		visited[cur] = 1;
		pathvisit[cur] = 1;
		for(int i=0; i<adjlist[cur].size(); i++){
			if(pathvisit[adjlist[cur][i]]){
				return 0;
			}
			if(!visited[adjlist[cur][i]]){
				if(!dfstrav(adjlist[cur][i],visited,pathvisit,adjlist)){
					return 0;
				}
			}
		}
		pathvisit[cur] = 0;
		return 1;
	}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, 0),pathvisit(numCourses,0);
        vector<vector<int>> adjlist(numCourses,vector<int>());
        for(int i=0; i<prerequisites.size(); i++){
        	adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0; i<numCourses; i++){
        	if(!visited[i]){
        		if(!dfstrav(i,visited,pathvisit,adjlist)){
        			return 0;
        		}
        	}
        }
        return 1;
    }
};