#include "bits/stdc++.h"
using namespace std;

void dekh(vector<int>arr,int n,int k,int sum,int index,int count,vector<vector<int>> &ar,vector<int> &curr){
    if(count==4){
        if(sum==k){
            if(find(ar.begin(),ar.end(),curr)==ar.end()){
                ar.push_back(curr);
            }
        }
        return;
    }
    if(index>n){
        return;
    }
    curr.push_back(arr[index]);
    dekh(arr,n,k,sum+arr[index],index+1,count+1,ar,curr);
    curr.pop_back();
    dekh(arr,n,k,sum,index+1,count,ar,curr);
    return;
}

vector<vector<int>> allFour(vector<int>arr,int n,int k){
    vector<vector<int>> ar;
    vector<int>curr;
    dekh(arr,n,k,0,0,0,ar,curr);
    for(int i=0;i<ar.size();i++){
        sort(ar[i].begin(),ar[i].end());
    }
    return ar;
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> ar = allFour(arr,n,k);
    for(int i=0;i<ar.size();i++){
        cout<<ar[i][0]<<" "<<ar[i][1]<<" "<<ar[i][2]<<" "<<ar[i][3]<<endl;
    }
    return 0;
}