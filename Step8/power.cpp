#include "bits/stdc++.h"
using namespace std;

long long int mod = 10e9+7;

long long int power(int N,int R){
    if(N==0){
        return 0;
    }
    if(R==0){
        return 1;
    }

    long long temp = power(N,R/2);
    if(R%2==0){
        return (temp*temp)%mod;
    }
    return (((N*temp)%mod)*temp)%mod;
}

signed main(){
    int N,R;
    cin>>N>>R;
    cout<<power(N,R);
    return 0;
}