
class Solution {
public:
    static bool compare(pair<int,char>& v1, pair<int,char>& v2){
        return (v1.first > v2.first);
    }
    string frequencySort(string s) {
        vector<pair<int,char>> arr;
        for(int i=0; i<10; i++){
            arr.push_back({0,char('0' + i)});
        }
        for(int i=0; i<26; i++){
            arr.push_back({0,char('a' + i)});
        }
        for(int i=0; i<26; i++){
            arr.push_back({0,char('A' + i)});
        }
        for(int i=0; i<s.size(); i++){
            if(s[i]<='9'){
                arr[s[i] - '0'].first++;
            }
            else if(s[i]>='a'){
                arr[s[i] - 'a' + 10].first++;
            }else{
                arr[s[i] - 'A' + 36].first++;
            }
        }
        sort(arr.begin(),arr.end(), compare);
        string ans = "";
        for(int i=0; i<62; i++){
            // cout<<arr[i].second<<" "<<arr[i].first<<endl;
            if(arr[i].first==0){
                continue;
            }
            for(int j=0; j<arr[i].first; j++){
                ans+=arr[i].second;
            }
        }
        return ans;
    }
};
