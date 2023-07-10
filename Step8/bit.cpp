#include "bits/stdc++.h"
using namespace std;

vector<int> bitManipulation(int num, int i){
    int count = 0;
    int number = 1;
    vector<int>vc;
    int temp = num;
    while(count!=i-1){
        temp = temp>>1;
        number = number<<1;
        count++;
    }
    vector<int>ans;
    ans.push_back(temp&1);
    ans.push_back(num|number);
    number = ~number;
    ans.push_back(num&number);
    return ans;   
}

signed main(){
    int num;
    cin>>num;
    int i;
    cin>>i;
    vector<int> ans = bitManipulation(num,i);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}