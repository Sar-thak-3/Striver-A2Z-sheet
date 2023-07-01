#include "bits/stdc++.h"
using namespace std;

void mergeW(int arr1[],int arr2[],int n,int m){
    int arr1N = 0;
    int arr2N = 0;
    while(arr1N<n){
        if(arr1[arr1N]<=arr2[arr2N]){
            arr1N++;
        }
        else{
            int temp = arr1[arr1N];
            arr1[arr1N] = arr2[arr2N];
            arr2[arr2N] = temp;
            sort(arr2,arr2+m);
            arr1N++;
        }
    }
    return;
}

signed main(){
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    mergeW(arr1,arr2,n,m);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
    return 0;
}