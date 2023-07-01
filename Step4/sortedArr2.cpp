#include "bits/stdc++.h"
using namespace std;

bool find(int n,vector<int>arr,int k,int start,int last){
    if(start>last){
        return false;
    }
    int mid = (start+last)/2;
    if(k==arr[mid]){
        return true;
    }
    bool normal;
    if(k>arr[start] and k<arr[last]){
        if(k>arr[mid]){
            if(find(n,arr,k,mid+1,last)){
                return true;
            };
        }
        else{
            if(find(n,arr,k,start,mid-1)){
                return true;
            }
        }
    }
    else{
        if(find(n,arr,k,start,mid-1)){
            return true;
        }
        if(find(n,arr,k,mid+1,last)){
            return true;
        }
    }
    return false;
}

bool search(int n,vector<int>arr,int k){
    return find(n,arr,k,0,n-1);
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<search(n,arr,k);
    return 0;
}