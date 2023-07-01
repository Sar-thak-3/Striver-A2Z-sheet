#include "bits/stdc++.h"
using namespace std;

void smallestDivisor(vector<int>a,int n,int start,int end,int &currAns){
    if(start>end){
        return;
    }
    int mid = (start+end)/2;
    int sum = 0;
    for(int i=0;i<a.size();i++){
        int div = a[i]/mid;
        if(mid*div==a[i]){
            sum += div;
        }
        else{
            sum += (div+1);
        }
    }
    if(sum<=n){
        if(mid<currAns){
            currAns = mid;
        }
        smallestDivisor(a,n,start,mid-1,currAns);
    }
    else{
        smallestDivisor(a,n,mid+1,end,currAns);
    }
    return;
}

signed main(){
    int n;
    cin>>n;
    vector<int> a{1,2,5,9};
    int currAns = INT_MAX;
    smallestDivisor(a,n,0,9,currAns);
    cout<<currAns;
    return 0;
}