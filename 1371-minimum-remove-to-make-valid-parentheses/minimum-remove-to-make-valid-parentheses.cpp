class Solution {
public:
    string minRemoveToMakeValid(string s){
        stack<int> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i]>='a' && s[i]<='z'){
                continue;
            }
            if(s[i]=='('){
                st.push(i);
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    s[i]='#';
                }
            }
        }
        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='#')
                ans.push_back(s[i]);
        }
        return ans;
    }
};