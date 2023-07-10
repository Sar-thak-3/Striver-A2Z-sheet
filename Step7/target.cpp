#include "bits/stdc++.h"
using namespace std;

vector<pair<int,string>> allstrings(string s,int target,string currStr,int curridx,vector<string>&ans){
    if(curridx>=s.size()){
        return vector<pair<int,string>>{};
    }
    if(curridx==s.size()-1){
        currStr += s[curridx];
        int r = stoi(currStr);
        cout<<r<<endl;
        return vector<pair<int,string>>{{r,currStr}};
    }

    currStr += s[curridx];

    if(s[curridx+1]=='0'){
        vector<pair<int,string>>a = allstrings(s,target,"",curridx+2,ans);
        vector<pair<int,string>> toreturn;
        int c = stoi(currStr+'0');
        for(int i=0;i<a.size();i++){
            toreturn.push_back({c+a[i].first,currStr+'0'+'+'+a[i].second});
            toreturn.push_back({c-a[i].first,currStr+'0'+'-'+a[i].second});
            toreturn.push_back({c*a[i].first,currStr+'0'+'*'+a[i].second});
            toreturn.push_back({c*10+a[i].first,currStr+a[i].second});
        }
        return toreturn;
    }

    vector<pair<int,string>>a = allstrings(s,target,"",curridx+1,ans);
    int c = stoi(currStr);
    vector<pair<int,string>> toreturn;
    for(int i=0;i<a.size();i++){
        if(curridx==0){
            cout<<c<<" "<<a[i].first<<endl;
            if(c+a[i].first==target){
                ans.push_back(currStr+'+'+a[i].second);
            }
            if(c-a[i].first==target){
                ans.push_back(currStr+'-'+a[i].second);
            }
            if(c*a[i].first==target){
                ans.push_back(currStr+'*'+a[i].second);
            }
            if(c*10+a[i].first==target){
                ans.push_back(currStr+a[i].second);
            }
        }
        toreturn.push_back({c+a[i].first,currStr+'+'+a[i].second});
        toreturn.push_back({c-a[i].first,currStr+'-'+a[i].second});
        toreturn.push_back({c*a[i].first,currStr+'*'+a[i].second});
        toreturn.push_back({c*10+a[i].first,currStr+a[i].second});
    }

    return toreturn;

}

signed main(){
    string s;
    cin>>s;
    int target;
    cin>>target;
    vector<string>ans;
    allstrings(s,target,"",0,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}