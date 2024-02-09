
class Solution {
public:
	bool hasCycle(vector<vector<int>>& adjlist, int cur, vector<bool>& visited, vector<bool>& pathvisit){
		visited[cur] = 1;
		pathvisit[cur]=1;
		for(int i=0; i<adjlist[cur].size(); i++){
			if(!visited[adjlist[cur][i]]){
				if(hasCycle(adjlist,adjlist[cur][i],visited,pathvisit)){
                    return 1;
                };
			}
			if(visited[adjlist[cur][i]] && pathvisit[adjlist[cur][i]]){
				return 1;
			}
		}
		pathvisit[cur]=0;
		return 0;
	}

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(n,vector<int>());
        for(int i=0; i<prerequisites.size(); i++){
        	adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> pathvisit(n,0);
        vector<bool> visited(n,0);
        for(int i=0; i<visited.size(); i++){
        	if(!visited[i]){
		        if(hasCycle(adjlist,i,visited,pathvisit)){
		        	return 0;
		        }
        	}
        }
        return 1;
    }
};

