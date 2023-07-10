#include "bits/stdc++.h"
using namespace std;

vector<vector<int> > fourSum(vector<int> &arr, int k) {
    int sum = 0;
    int count = 0;
    vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            int tempk = k-arr[i]-arr[j];
            vector<bool> vc(1000,false);
            for(int k=j+1;k<arr.size();k++){
                if((tempk-arr[k])>=0 and vc[tempk-arr[k]] and !vc[arr[k]]){
                    ans.push_back(vector<int>{arr[i],arr[j],tempk-arr[k],arr[k]});
                }
                vc[arr[k]] = true;
            }
        }
    }
    return ans;
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>ans = fourSum(a,k);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}