#include "bits/stdc++.h"
using namespace std;

long long int largestSumSubarray(long long int k,vector<long long int>arr){
    long long int maxx = INT_MIN;
    long long int currSum = 0;
    for(int i=0;i<k;i++){
        currSum+=arr[i];
    }
    long long int start = 0;
    long long int lastSum = 0;
    maxx = currSum;
    for(long long int i=k;i<arr.size();i++){
        currSum += arr[i];
        maxx = max(maxx,currSum);
        lastSum += arr[start];
        start++;
        if(lastSum<0){
            currSum -= lastSum;
            maxx = max(maxx,currSum);
            lastSum = 0;
        }
    }
    return maxx;
}

signed main(){
    long long int n;
    cin>>n;
    vector<long long int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int k;
    cin>>k;
    cout<<largestSumSubarray(k,arr);
    return 0;
}