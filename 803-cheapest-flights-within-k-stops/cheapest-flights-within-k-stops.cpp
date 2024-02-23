class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjlist(n,vector<pair<int,int>>());
        for(int i=0; i<flights.size(); i++){
            adjlist[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>dist(n, 10e6);
        dist[src] = 0;
        queue<vector<int>> pending;
        pending.push({k,src,0});
        int ans = 10e6;
        while(!pending.empty()){
            int len = pending.size();
            for(int l=0; l<len; l++){
                int stop = pending.front()[0];
                int source = pending.front()[1];
                int distance = pending.front()[2];
                pending.pop();
                for(int i=0; i<adjlist[source].size(); i++){
                    int newdist = distance + adjlist[source][i].second;
                    if(dst==adjlist[source][i].first){
                        ans = min(newdist,ans);
                        continue;
                    }
                    if(stop>0 && newdist<dist[adjlist[source][i].first]){
                        dist[adjlist[source][i].first] = newdist;
                        pending.push({stop-1,adjlist[source][i].first,newdist});
                    }
                }
            }
        }
        return (ans==10e6)? -1:ans;
    }
};