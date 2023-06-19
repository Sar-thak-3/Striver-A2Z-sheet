#include "bits/stdc++.h"
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int summ = 0;
    int start = 0;
    int ans = 0;
    for(int i=0;i<arr.size();i++){
        summ += arr[i];
        if(summ==k){
            ans++;
            summ -= arr[start];
            start++;
        }
        else if(summ>k){
            while(summ>k){
                summ -= arr[start];
                start++;
            }
            
            if(summ==k){
                ans++;
                summ -= arr[start];
                start++;
            }
        }
    }
    return ans;
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findAllSubarraysWithGivenSum(arr,k);
    return 0;
}