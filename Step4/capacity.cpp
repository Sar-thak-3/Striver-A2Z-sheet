#include "bits/stdc++.h"
using namespace std;

int findays(int arr[],int N,int cap)
  {
    int days=1;
    int load=0;
    for(int i=0;i<N;i++)
    {
        if(arr[i]+load>cap)
        {
            days+=1;
            load=arr[i];
        }
        else
        {
            load+=arr[i];
        }
    }
    return days;
  }

int leastWeight(int N, int D, int arr[])
{
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        sum = sum + arr[i];
        maxi = max(maxi, arr[i]);
    }
    int low = maxi;
    int high = sum;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int number = findays(arr, N, mid);
        if (number <= D)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

signed main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << leastWeight(n, d, arr);
    return 0;
}