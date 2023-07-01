#include "bits/stdc++.h"
using namespace std;

int NthRoot(int n, int m){
	double r = pow(m,double(1/double(n)));
    int power = pow(r,n);
    cout<<power<<endl;
	if(power==m){
        cout<<"hgvh"<<endl;
	    return r;
	}
	return -1;
}

signed main(){
    int n,m;
    cin>>n>>m;
    cout<<NthRoot(n,m);
    return 0;
}