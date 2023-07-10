#include "bits/stdc++.h"
using namespace std;

long long mod = 10e9+7;

long long power(int n,int r){
    long long ans = 1;
    while(r!=0){
        if(r%2==0){
            r = r/2;
            long long t = pow(n,r);
            t = t%mod;
            t *= (t%mod);
            ans *= t%mod;
        }
        else{
            r = r/2;
            long long t = pow(n,r);
            t = t%mod;
            t *= (t%mod);
            if(r!=1){
                t *= n;
            }
            ans *= t%mod;
        }
    }
    return ans;
}

signed main(){
    int n,r;
    cin>>n>>r;
    cout<<power(n,r);
    return 0;
}