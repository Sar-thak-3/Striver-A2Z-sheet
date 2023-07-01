#include "bits/stdc++.h"
using namespace std;

pair<int,int> maxPages(int A[],int N,int M,int mid){
        int maxx = INT_MIN;
        int currBooks = 0;
        int currSum = 0;
        int readers = 0;
        for(int i=0;i<N;i++){
            currSum += A[i];
            currBooks++;
            if(currBooks==mid or i==N-1){
                maxx = max(maxx,currSum);
                currBooks = 0;
                currSum = 0;
                readers++;
            }
        }
        return {maxx,readers};
    }

int findPages(int A[], int N, int M) {
        int start = 1;
        int end = N;
        int ans = INT_MAX;
        while(start<=end){
            int mid = (start+end)/2;
            pair<int,int> mp = maxPages(A,N,M,mid);
            if(mp.second>=M){
                start = mid+1;
                ans = min(ans,mp.first);
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }

signed main(){
    int n,m;
    cin>>n>>m;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<findPages(A,n,m);
    return 0;
}