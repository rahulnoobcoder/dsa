#include <bits/stdc++.h>
using namespace std;

int ways(int n,int i,int arr[],int target,int sum){

    if (i==n){
        return target==sum;
    }


    int pos=ways(n,i+1,arr,target,sum+arr[i]);
    int neg=ways(n,i+1,arr,target,sum-arr[i]);

    return pos+neg;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,target;
    cin >> n>>target;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout<<ways(n,0,arr,target,0);

    return 0;
}