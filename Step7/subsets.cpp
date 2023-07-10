#include "bits/stdc++.h"
using namespace std;

// int number(vector<int>arr,int n,int k){
//     vector<vector<bool>> vp(n,vector<bool>(k+1,false));
//     for(int i=0;i<n;i++){
//         vp[i][arr[i]] = true;
//         for(int j=0;j<arr[i]+1;j++){
//             if(i-1>=0 and vp[i-1][j]){
//                 vp[i][j] = true;
//                 if(j+arr[i]<= k ){
//                     vp[i][j+arr[i]] = true;
//                 }
//             }
//         }
//     }
//     int count = 0;
//     for(int i=0;i<n;i++){
//         if(vp[i][k]){
//             count++;
//         }
//     }
//     return count;
// }

void number(vector<int> arr,int n,int k,int currSum,int index,vector<int> currVec,set<vector<int>>&counts){
    if(index>=n){
        if(currSum==k){
            counts.insert(currVec);
        }
        return;
    }
    currVec.push_back(arr[index]);
    number(arr,n,k,currSum+arr[index],index+1,currVec,counts);
    currVec.pop_back();
    number(arr,n,k,currSum,index+1,currVec,counts);
    return;
}

signed main(){
    int n,k;cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    set<vector<int>> counts;
    number(arr,n,k,0,0,vector<int>{},counts);
    vector<vector<int>> ans;
        set<vector<int>>::iterator it;
        for(auto it=counts.begin();it!=counts.end();it++){
            ans.push_back(*it);
        }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}