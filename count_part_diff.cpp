#include <bits/stdc++.h>
using namespace std;


int count(int arr[],int i, int sum,int target,int total,int n){
    if ((target + total) % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    if (i==n){
        if (sum == (target+total)/2) return 1;
        return 0;
    }

    // if (sum <= target && dp[i][sum]!=-1) return dp[i][sum];
    
    int take = count(arr, i + 1, sum + arr[i], target,total, n);
    int ntake=count(arr,i+1,sum,target,total,n);    
    return take+ntake;
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
    int total=0;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        total+=arr[i];
    

    cout<<count(arr,0,0,target,total,n);
    return 0;
}