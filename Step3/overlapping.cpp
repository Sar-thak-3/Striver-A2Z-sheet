#include "bits/stdc++.h"
using namespace std;

bool sorting(vector<int>s1,vector<int>s2){
    return s1[1]<s2[1];
}

vector<vector<int>> overlappingIntervals(vector<vector<int>> arr){
    sort(arr.begin(),arr.end(),sorting);
    vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++){
        if(ans.empty()){
            ans.push_back(arr[i]);
        }
        if(ans.back()[0]>arr[i][0]){
            ans[ans.size()-1][0] = arr[i][0];
        }
        if(ans.back()[1]>=arr[i][0]){
            if(ans.back()[1]<arr[i][1]){
                ans[ans.size()-1][1] = arr[i][1];
            }
        }
        else{
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));

    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    vector<vector<int>>ans = overlappingIntervals(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}