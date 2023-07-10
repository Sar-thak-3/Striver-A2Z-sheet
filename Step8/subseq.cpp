#include "bits/stdc++.h"
using namespace std;

vector<string> subsequences(string str){
	int size = str.size();
	int start = 1;
	vector<string>ans;
	while(start!=pow(2,size)){
		int temp = start;
		string curr = "";
		for(int i=0;i<str.size();i++){
			if(temp&1){
				curr += str[i];
			}
			temp = temp>>1;
		}
		ans.push_back(curr);
		start++;
	}
	return ans;
}

signed main(){
    string s;
    cin>>s;
    vector<string>ans = subsequences(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}