#include "bits/stdc++.h"
using namespace std;

int kthElement(vector<int>arr1,vector<int>arr2,int k){
    int start1 = 0,start2=0;
    int end1 = arr1.size()-1,end2 = arr2.size()-1;

    int count = 0;
    while(true){
        int mid1 = (start1+end1)/2;
        int mid2 = (start2+end2)/2;
        if(arr1[mid1]<arr2[mid2]){
            end2 = mid2-1;
        }
        else{
            count += mid1-start1;
            count += mid2-start2+1;
        }
        if(count>k){
            end1 = mid1-1;
            end2 = mid2-1;
        }
        else{
            start1 = mid1+1;
            start2 = mid2+1;
        }
        if(count==k or count+1==k){
            break;
        }
    }
    if(count==k){
        return arr2[(start2+end2)/2];
    }
    return arr1[(start1+end1)/2];
}

signed main(){
    vector<int>arr1{100,112,256,349,770};
    vector<int>arr2{72,86,113,119,265,445,892};
    int k=7;
    cout<<kthElement(arr1,arr2,k);
    return 0;
}