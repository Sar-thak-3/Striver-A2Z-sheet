#include "bits/stdc++.h"
using namespace std;

bool exist(vector<vector<char>> vc,string word,int index,string currWord,int row,int col){
    if(currWord==word){
        return true;
    }
    if(row>=vc.size() or col>=vc[0].size()){
        return false;
    }

    if(vc[row][col]==word[index]){
        if(exist(vc,word,index+1,currWord+vc[row][col],row+1,col)){
            return true;
        }
        if(exist(vc,word,index+1,currWord+vc[row][col],row,col+1)){
            return true;
        }
    }
    return exist(vc,word,index,currWord,row+1,col) || exist(vc,word,index,currWord,row,col+1);
}

signed main(){
    vector<vector<char>> vc{{'a','b','d','f'},{'b','c','d','f'},{'z','x','y','u'},{'v','o','p','y'}};
    cout<<exist(vc,"abcd",0,"",0,0);
    return 0;
}