#include "bits/stdc++.h"
using namespace std;

int matSearch (vector <vector <int>> &mat, int N, int M, int X){
	bool exists = false;
	int start = 0;
	int end = N;
	
	while(start<=end){
	    int mid = (start+end)/2;
	    if(X>=mat[mid][0] and X<=mat[mid][M-1]){
	        bool find = false;
	        for(int i=0;i<M;i++){
	            if(mat[mid][i]==X){
	                find = true;
	            }
	        }
	        if(find){
	            exists = true;
	        }
	        break;
	    }
	    else if(X<mat[mid][0]){
	        end = mid-1;
	    }
	    else{
	        start = mid+1;
	    }
	}
	return exists;
}

signed main(){
    int N=1,M=5;
    vector<vector<int>> mat{{3,11,27,50,52}};
    int X=65;
    cout<<matSearch(mat,N,M,X);
    return 0;
}