#include "bits/stdc++.h"
using namespace std;

double maxDist(vector<double> arr,int n,int k){
    priority_queue<double> pq;
    for(int i=1;i<n;i++){
        pq.push(arr[i]-arr[i-1]);
        // pq.push(floor((arr[i]-arr[i-1])*100.0)/100.0);
    }

    for(int i=0;i<k;i++){
        double top = pq.top();
        pq.pop();
        pq.push(floor((top/2)*100.0)/100.0);
        pq.push(floor((top/2)*100.0)/100.0);
    }
    return pq.top();
}

signed main(){
    // int n;
    // cin>>n;
    // vector<double>arr(n);
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // int k;
    // cin>>k;
    double t = 12.757;
    cout<<floor(t*100.0)/100.0<<endl;
    cout<<floor((t/2)*100.0)/100.0<<endl;
    // cout<<maxDist(arr,n,k);
    return 0;
}