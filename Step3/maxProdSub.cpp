#include "bits/stdc++.h"
using namespace std;

long long int maxProduct(vector<int>arr,int n){
    long long int currProd = INT_MIN,maxProd=INT_MIN;
	int countNeg = 0;
	int maxNeg = INT_MIN;
	for(int i=0;i<n;i++){
	    if(arr[i]==0){
	        long long int zero = 0;
	        if(countNeg%2==0){
	            maxProd = max(maxProd,max(zero,currProd));   
	        }
	        else{
	            currProd = currProd / maxNeg;
	            maxProd = max(maxProd,max(zero,currProd));
	        }
	        currProd = INT_MIN;
	        countNeg = 0;
	        maxNeg = INT_MIN;
            continue;
	    }       
	    if(arr[i]<0){
	        maxNeg = max(maxNeg,arr[i]);
	        countNeg++;
	    }
	    if(currProd==INT_MIN){
	        currProd = arr[i];
	    }
	    else{
	        currProd *= arr[i];   
	    }
        cout<<currProd<<endl;
	}
	if(countNeg%2==0 or arr.size()==1){
	    maxProd = max(maxProd,currProd);
	}
	else{
	    currProd = currProd/maxNeg;
	    maxProd = max(maxProd,currProd);
	}
	return maxProd;
}

signed main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxProduct(arr,n);
    return 0;
}