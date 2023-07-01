#include "bits/stdc++.h"
using namespace std;

int median(vector<vector<int>> &matrix, int R, int C){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;
    for(int i=0;i<C;i++){
        pq.push({matrix[0][i],i});
    }

    // cout<<pq.top().first<<" "<<pq.top().second<<endl;

    vector<int> arr;
    vector<int>rowData(C,0);
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        arr.push_back(temp.first);
        if(rowData[temp.second]+1>=R){
            continue;
        }
        pq.push({matrix[rowData[temp.second]+1][temp.second] , temp.second});
        rowData[temp.second]++;
    }

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    int mid = arr.size()/2;
    if(arr.size()%2==0){
        return (arr[mid-1]+arr[mid])/2;
    }
    return arr[mid];
}

signed main(){
    int R=3,C=1;
    vector<vector<int>>matrix{{1},{2},{3}};
    cout<<median(matrix,R,C);
    return 0;
}