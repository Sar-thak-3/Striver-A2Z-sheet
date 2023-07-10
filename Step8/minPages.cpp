#include "bits/stdc++.h"
using namespace std;

int findPages(int A[], int N, int M) {
    vector<int>vc;
    int minn = INT_MAX;
    for(int i=0;i<M;i++){
        vc.push_back(A[i]);
        minn = min(minn,vc[i]);
    }
    for(int i=M;i<N;i++){
        bool find = false;
        for(int j=0;j<M;j++){
            if(minn==vc[j] and !find){
                find = true;
                if(j!=M-1){
                    if(j-1>=0 and vc[j]+vc[j-1]<vc[j]+vc[j+1]){
                        vc[j-1] += vc[j];
                        vc[j] = vc[j+1];
                    }
                    else{
                        vc[j] += vc[j+1];
                    }
                }
                else{
                    if(vc[j]+vc[j-1]<vc[j]+A[i]){
                        vc[j-1] += vc[j];
                        vc[j] = A[i];
                    }
                    else{
                        vc[j] += A[i];
                    }
                }
            }
            else if(find){
                if(j!=M-1){
                    vc[j] = vc[j+1];
                }
                else{
                    vc[j] = A[i];
                }
            }
        }
        minn = INT_MAX;
        for(int j=0;j<M;j++){
            minn = min(minn,vc[j]);
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<M;i++){
        ans = max(ans,vc[i]);
    }
    return ans;
}

signed main(){
    int N,M;
    cin>>N>>M;
    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<findPages(A,N,M);
    return 0;
}