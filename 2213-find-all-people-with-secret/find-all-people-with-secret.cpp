
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>>temp(n);
        for(int i=0; i<meetings.size(); i++){
            temp[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            temp[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        vector<bool>visited(n);
        while(!pq.empty()){
            int t = pq.top().first;
            int x = pq.top().second;
            pq.pop();
            if(visited[x]){
                continue;
            }
            visited[x]=1;
            for(int i=0; i<temp[x].size(); i++){
                if(visited[temp[x][i].first]){
                    continue;
                }
                if(temp[x][i].second >= t){
                    pq.push({temp[x][i].second,temp[x][i].first});
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(visited[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};