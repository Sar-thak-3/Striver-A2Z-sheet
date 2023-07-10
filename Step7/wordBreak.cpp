#include "bits/stdc++.h"
using namespace std;

void allstrings(string s,int index,vector<string>words,string curr,string completestr,vector<string>&ans,int maxx){
    if(index>=s.size()){
        if(completestr!="" and completestr.size()>=s.size()+maxx){
            ans.push_back(completestr);
        }
        return;
    }

    curr+=s[index];
    if(find(words.begin(),words.end(),curr)!=words.end()){
        if(completestr!=""){
            allstrings(s,index+1,words,"",completestr+" "+curr,ans);
        }
        else{
            allstrings(s,index+1,words,"",completestr+curr,ans);
        }
    }
    allstrings(s,index+1,words,curr,completestr,ans);
    return;
}

signed main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string>words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }

    vector<string>ans;
    int maxx = INT_MIN;
        for(int i=0;i<n;i++){
            int t = words[i].size();
            maxx = max(maxx,t);
        }
        int temp = s.size()/maxx; 
    allstrings(s,0,words,"","",ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}