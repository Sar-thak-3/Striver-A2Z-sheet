#include "bits/stdc++.h"
using namespace std;

vector<int> goodnumbers(int L,int R,int D){
    vector<int>ans;
    for(int i=L+1;i<R;i++){
        int temp = i;
        int last = temp%10;
        temp = temp/10;
        bool exist = true;
        if(last==D){
            exist = false;
        }
        while(temp!=0){
            if(temp%10 <= last or temp%10==D){
                exist = false;
                break;
            }
            last += temp%10;
            temp = temp/10;
        }
        if(exist){
            ans.push_back(i);
        }
    }
    return ans;
}

signed main(){
    int L,R,D;
    cin>>L>>R>>D;
    vector<int>ans = goodnumbers(L,R,D);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}