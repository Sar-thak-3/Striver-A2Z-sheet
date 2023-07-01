#include "bits/stdc++.h"
using namespace std;

string remove(string s){
    stack<char> st;
    string ans = "";
    bool start = true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            if(start){
                start = false;
                continue;
            }
            else{
                ans += '(';
                st.push(s[i]);
            }
        }
        else{
            if(st.size()==0){
                start = true;
                continue;
            }
            else{
                ans += ')';
                st.pop();
            }
        }
    }
    return ans;
}

signed main(){
    string s;
    cin>>s;
    cout<<remove(s);
    return 0;
}