#include "bits/stdc++.h"
using namespace std;

bool areIsomorphic(string str1, string str2){
    if(str1.size()!=str2.size()){
        return false;
    }
    vector<int> last(26,-1);
    vector<int> last2(26,-1);
    for(int i=0;i<str2.size();i++){
        if(last[str1[i]-'a']==-1){
            last[str1[i]-'a'] = i;
        }
        else{
            if((str1[last[str1[i]-'a']]==str1[i]) and (str2[last[str1[i]-'a']]==str2[i])){
                last[str1[i]-'a'] = i;   
            }
            else{
                return false;
            }
        }
    }
    for(int i=0;i<str1.size();i++){
        if(last2[str2[i]-'a']==-1){
            last2[str2[i]-'a'] = i;
        }
        else{
            if((str2[last2[str2[i]-'a']]==str2[i]) and (str1[last2[str2[i]-'a']]==str1[i])){
                last2[str2[i]-'a'] = i;   
            }
            else{
                return false;
            }
        }
    }
    return true;
}

signed main(){
    string str1,str2;
    cin>>str1>>str2;
    cout<<areIsomorphic(str1,str2);
    return 0;
}