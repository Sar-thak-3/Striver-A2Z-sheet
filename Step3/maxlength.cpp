#include "bits/stdc++.h"
using namespace std;

int lenOfLongSubarr(int A[],  int N, int K) {
    int start = 0;
    int sum=0;
    int maxi = 0;
    for(int i=0;i<N;i++){
        sum+=A[i];
        if(sum==K){
            maxi = max(maxi,i-start+1);
            sum -= A[start];
            start++;
        }
        else if(sum>K){
            sum -= A[start];
            start++;
        }
    }
    return maxi;
} 

signed main(){
    int N,K;
    cin>>N>>K;
    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<lenOfLongSubarr(A,N,K);
    return 0;
}