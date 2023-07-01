#include "bits/stdc++.h"
using namespace std;

int atmostK(string s ,int k){
    map<char,int>mp;
    int start = 0;
    int num = 0;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
        while(mp.size()>k){
            mp[s[start]]--;
            if(mp[s[start]]==0){
                mp.erase(s[start]);
            }
            start++;
        }
        num += i-start+1;
    }
    return num;
}

int counts(string s,int k){
    int kk = atmostK(s,k);
    int kkk = atmostK(s,k-1);
    cout<<kk<<" "<<kkk<<endl;
    return kk-kkk;
}

signed main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<counts(s,k);
    return 0;
}