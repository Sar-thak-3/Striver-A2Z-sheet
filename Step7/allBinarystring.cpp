#include "bits/stdc++.h"
using namespace std;

void allstrings(string s,vector<string> &ans,int index){
    if(index>=s.size()){
        if(find(ans.begin(),ans.end(),s)==ans.end()){
            ans.push_back(s);
        }
    }
    for(int i=index;i<=s.size();i++){
        s[i] = '1';
        allstrings(s,ans,i+2);
        s[i] = '0';
        // allstrings(s,ans,index+2);
    }
    return;
}

signed main(){
    int k;
    cin>>k;
    string s = "0000";
    vector<string> ans;
    allstrings(s,ans,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}