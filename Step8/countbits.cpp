#include "bits/stdc++.h"
using namespace std;

int countNoOfSetBits(int num){
	int sum = 0;
	int bitindex = 0;
	int temp = num;
	while(temp!=0){
		int start = pow(2,bitindex);
		int diff = pow(2,bitindex+1);
		int count = num/diff;
		sum += count*(start);
		int completed = start-1+(count*diff);
		sum += num-completed;
		bitindex++;
		temp = temp>>1;
        cout<<sum<<endl;
	}
	// int sum = 0;
	// for(int i=1;i<=num;i++){
	// 	int temp = i;
	// 	while(temp!=0){
	// 		if(temp&1){
	// 			sum ++;
	// 		}
	// 		temp = temp>>1;
	// 	}
	// }
	return sum;
}

signed main(){
    int num;
    cin>>num;
    cout<<countNoOfSetBits(num);
    return 0;
}