#include <bits/stdc++.h>
using namespace std;

int solve(int arr[],int i,int n, int dp[],int k){
    if (i>=n-1){
        return 0;
    }

    if (dp[i]!=-1){
        return dp[i];
    }

    int mins=INT_MAX;

    for(int j=1;j<=k;j++){
        if (i+j < n){
            int temp=solve(arr,i+j,n,dp,k)+abs(arr[i]-arr[i+j]);
            mins=min(mins,temp);
        }
    }

    return dp[i]=mins;
}




int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,k;
    cin >> n>>k;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int dp[n];
    memset(dp,-1,sizeof(dp));

    cout<<solve(arr,0,n,dp,k);
    return 0;
}
