#include "bits/stdc++.h"
using namespace std;

int countPrimes(int n){
    vector<bool>vc(n+1,false);
    for(int i=2;i*i<=n;i++){
        int temp = i;
        int table = 2;
        while(temp*table<=n){
            vc[temp*table] = true;
            table++;
        }
    }
    int ans = 0;
    for(int i=2;i<n+1;i++){
        if(!vc[i]){
            cout<<i<<endl;
            ans++;
        }
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    cout<<countPrimes(n);
    return 0;
}