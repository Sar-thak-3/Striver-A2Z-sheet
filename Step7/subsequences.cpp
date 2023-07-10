#include "bits/stdc++.h"
using namespace std;

void subseq(string s,int index,vector<string> &all,string currstr){
    if(index>=s.size()){
        return;
    }
    all.push_back(currstr+s[index]);
    subseq(s,index+1,all,currstr+s[index]);
    subseq(s,index+1,all,currstr);
    return;
}

signed main(){
    string s;
    cin>>s;
    vector<string> ans;
    subseq(s,0,ans,"");
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}