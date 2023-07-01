#include "bits/stdc++.h"
using namespace std;

// int returnBeauty(string s){
//     map<char,int> mp;
//     int maxx = INT_MIN;
//     int minn = INT_MAX;
//     for(int i=0;i<s.size();i++){
//         mp[s[i]]++;
//     }
//     map<char,int>::iterator it;
//     for(auto it=mp.begin();it!=mp.end();it++){
//         maxx = max(maxx,it->second);
//         minn = min(minn,it->second);
//     }
//     return maxx-minn;
// }

// int beautySum(string s) {
//     int sum = 0;
//     vector<string> substrings;
//     for(int i=s.size();i>2;i--){
//         for(int j=0;j<=s.size()-i;j++){
//             if(find(substrings.begin(),substrings.end(),s.substr(j,j+i))==substrings.end()){
//                 sum += returnBeauty(s.substr(j,j+i));
//                 substrings.push_back(s.substr(j,j+i));
//             }
//         }
//     }
//     return sum;
// }

int beauty(string s){
    int ans = 0;
    for(int i=0;i<s.size();i++){
        unordered_map<char,int> mp;
        int count = 0;
        int minn = INT_MAX;
        int maxx = INT_MIN;
        char minchar = '/';
        for(int j=i;j<s.size();j++){
            mp[s[j]]++;
            count++;
            unordered_map<char,int>::iterator it;
            for(auto it=mp.begin();it!=mp.end();it++){
                minn = min(minn,it->second);
            }
            maxx = max(maxx,mp[s[j]]);
            if(minn==maxx){
                minn = INT_MAX;
                continue;
            }
            else{
                ans += maxx-minn;
            }
            minn = INT_MAX;
        }
    }
    return ans;
}

signed main(){
    string s;
    cin>>s;
    cout<<beauty(s);
    return 0;
}