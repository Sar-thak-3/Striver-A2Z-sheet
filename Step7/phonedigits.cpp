#include "bits/stdc++.h"
using namespace std;

vector<vector<char>> phone{{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

void allstrings(vector<int>a,int index,vector<string> &all,string currstr){
    if(index>=a.size()){
        all.push_back(currstr);
        return ;
    }
    if(a[index]==0 or a[index]==1){
        allstrings(a,index+1,all,currstr);
    }
    for(int i=0;i<phone[a[index]].size();i++){
        allstrings(a,index+1,all,currstr+phone[a[index]][i]);
    }
    return;
}

signed main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<string>all;
    allstrings(a,0,all,"");
    for(int i=0;i<all.size();i++){
        cout<<all[i]<<" ";
    }
    return 0;
}