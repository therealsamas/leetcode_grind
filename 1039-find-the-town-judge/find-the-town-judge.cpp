class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<set<int>> adjlist(n+1);
        for(int i=0; i<trust.size(); i++){
            adjlist[trust[i][0]].insert(trust[i][1]);
        }
        int a = 0;
        for(int i=1; i<=n; i++){
            if(adjlist[i].empty()){
                a = i;
            }
        }
        for(int i=1; i<=n; i++){
            if(i != a && adjlist[i].find(a) == adjlist[i].end()){
                return -1;
            }
        }
        return a;
    }
};
