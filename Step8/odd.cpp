#include "bits/stdc++.h"
using namespace std;

int missingNumber(int n, vector<int> &arr){
    map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
        if(mp[arr[i]]==2){
            mp.erase(arr[i]);
        }
    }
    map<int,int>::iterator it=mp.begin();
    return it->first;
}

signed main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<missingNumber(n,arr);
    return 0;
}