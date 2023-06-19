#include "bits/stdc++.h"
using namespace std;

void stocksBuySell(vector<int> arr,int n){
    vector<pair<int,int>> vc;
    int buy = 0;
    int sell = 0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[sell]){
            if(sell>buy){
                vc.push_back({buy,sell});
            }
            buy = i;
            sell = i;
        }
        else if(arr[i]>arr[sell]){
            sell = i;
        }
    }
    if(buy<sell){
        vc.push_back({buy,sell});
    }

    if(vc.size()==0){
        cout<<"No profit"<<endl;
    }
    else{
        for(int i=0;i<vc.size();i++){
            cout<<'('<<vc[i].first<<" "<<vc[i].second<<") ";
        }
    }
    return;
}

signed main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stocksBuySell(arr,n);
    return 0;
}