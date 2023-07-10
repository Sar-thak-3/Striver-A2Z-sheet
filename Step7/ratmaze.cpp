#include "bits/stdc++.h"
using namespace std;

void allstrings(vector<vector<int>>m,int row,int col,vector<string>&ans,string curr){
    if(row==m.size()-1 and col==m.size()-1){
        ans.push_back(curr);
        return;
    }
    if(row>=m.size() or col>=m.size()){
        return;
    }

    if(row+1<m.size() and m[row+1][col]==1){
        allstrings(m,row+1,col,ans,curr+'D');
    }
    if(col+1<m.size() and m[row][col+1]==1){
        allstrings(m,row,col+1,ans,curr+'R');
    }
    return;
}

signed main(){
    int n;
    cin>>n;
    vector<vector<int>>m(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }
    vector<string> ans;
    allstrings(m,0,0,ans,"");
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}