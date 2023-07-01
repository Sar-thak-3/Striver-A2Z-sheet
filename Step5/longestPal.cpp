#include "bits/stdc++.h"
using namespace std;

void getMaxsol(string s, string &ans, int &mx,int l,int r){
    while(l>=0 && r<s.length() && s[l]==s[r]){
      if(r-l+1>mx)  {
          ans=s.substr(l,r-l+1);
          mx=r-l+1;
      }
       l--;
    r++;
    }
}

string longestPalin (string S) {
    string ans="";
    int mx=0;
    
    for(int i=0;i<S.length();i++){
        getMaxsol(S,ans,mx,i,i);
        getMaxsol(S,ans,mx,i,i+1);
    }
    return ans;
}

signed main(){
    string s;
    cin>>s;
    cout<<longestPalin(s);
    return 0;
}