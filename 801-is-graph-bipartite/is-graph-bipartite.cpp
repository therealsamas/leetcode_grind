class Solution {
public:

	bool dfstrav(bool c, int cur, int parent, vector<vector<int>>& adjlist, vector<int >& colours){
		colours[cur] = c;
		for(int i=0; i<adjlist[cur].size(); i++){
			if(parent == adjlist[cur][i]){
				continue;
			}
			if(colours[adjlist[cur][i]] == 2){
				if(!dfstrav(!c,adjlist[cur][i],cur, adjlist,colours)){
					return 0;
				}
			}
			else if(!c != colours[adjlist[cur][i]]){
				return 0;
			}
		}
		return 1;
	}

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colours(graph.size(),2);
        for(int i=0; i<graph.size(); i++){
        	if(colours[i]==2){
        		if(!dfstrav(1,i,i,graph,colours)){
        			return 0;
        		}
        	}
        }
        return 1;
    }
};