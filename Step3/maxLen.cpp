#include "bits/stdc++.h"
using namespace std;

int maxlength(vector<int>A,int n){
    int sum = 0;
    int longsum = 0;
    map<int,int> mp;
    mp[0] = -1;
    for(int i=0;i<n;i++){
        sum += A[i];
        if(mp.find(sum)!=mp.end()){
            longsum = max(longsum,i-mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }
    return longsum;
}

signed main(){

    return 0;
}