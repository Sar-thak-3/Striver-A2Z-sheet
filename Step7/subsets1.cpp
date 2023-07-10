#include "bits/stdc++.h"
using namespace std;

void allsums(vector<int>arr,int index,int currSum,vector<int>&sums){
    if(index>=arr.size()){
        sums.push_back(currSum);
        return;
    }

    allsums(arr,index+1,currSum+arr[index],sums);
    allsums(arr,index+1,currSum,sums);
}

signed main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>sums;
    allsums(arr,0,0,sums);
    sort(sums.begin(),sums.end());
    for(int i=0;i<sums.size();i++){
        cout<<sums[i]<<" ";
    }
    return 0;
}