#include "bits/stdc++.h"
using namespace std;

vector<int> lead(int a[],int n){
    stack<int> st;
    st.push(a[0]);
    for(int i=1;i<n;i++){
        while(!st.empty() and st.top()<a[i]){
            st.pop();
        }
        st.push(a[i]);
    }
    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    vector<int> ans;
    while(!temp.empty()){
        ans.push_back(temp.top());
        temp.pop();
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> ans = lead(a,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}