#include "bits/stdc++.h"
using namespace std;

void allnums(int index,int K,vector<int> currvec,int currsum,vector<vector<int>> &vecs){
    if(currsum>K){
        return;
    }
    if(index>=10){
        if(currsum==K){
            vecs.push_back(currvec);
        }
        return;
    }
    allnums(index+1,K,currvec,currsum,vecs);
    currvec.push_back(index);
    allnums(index+1,K,currvec,currsum+index,vecs);
    return;
}

vector<vector<int>> combinations(int K,int N){
    vector<vector<int>> ans;
    int sum = 0;
    for(int i=1;i<1+K;i++){
        sum += i;
    }
    if(sum>N){
        return ans;
    }
    sum = 0;
    for(int i=9;i>9-K;i--){
        sum += i;
    }
    if(sum<N){
        return ans;
    }

    vector<vector<int>>vecs;
    allnums(1,K,)
}

signed main(){

    return 0;
}