#include "bits/stdc++.h"
using namespace std;

void parenthesis(int k,stack<char>st,int rem,string curr,vector<string>&ans){
    if(rem==0){
        while(!st.empty()){
            curr += st.top();
            st.pop();
        }
        ans.push_back(curr);
        return;
    }

    curr += '(';
    st.push(')');
    parenthesis(k,st,rem-1,curr,ans);
    st.pop();

    while(!st.empty()){
        curr += st.top();
        st.pop();
    }
    parenthesis(k,st,rem-1,curr,ans);
    return;
}

signed main(){
    int k;
    cin>>k;
    vector<string> ans;
    stack<char> st;
    parenthesis(k,st,k,"",ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}