#include "bits/stdc++.h"
using namespace std;

bool checkRotation(string s1,string s2,int index1,int index2){
    int indexof2 = index2;
    for(int i=index1;i<s1.size();i++){
        if(s1[i]!=s2[indexof2]){
            return false;
        }
        indexof2++;
    }
    for(int i=0;i<index1;i++){
        if(s1[i]!=s2[indexof2]){
            return false;
        }
        indexof2++;
    }
    return true;
}

bool areRotations(string s1,string s2){ 
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[0]){
            if(checkRotation(s1,s2,i,0)){
                return true;
            }
        }
    }
    return false;
}

signed main(){
    return 0;
}