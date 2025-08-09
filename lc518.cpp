#include <bits/stdc++.h>
using namespace std;

int count(int i,int target,int coins[],int **dp){
        if (target==0){
            return 1;
        }
        if (i==0){
            return (target % coins[0] == 0);
        }
        if (target<0 || i<0){
            return 0;
        }
        if (dp[i][target]!=-1) return dp[i][target];
        int take=count(i,target-coins[i],coins,dp);
        int ntake=count(i-1,target,coins,dp);

        return dp[i][target]=take+ntake;
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
    int** dp=new int*[n];
    for(int i=0;i<n;i++){
        dp[i]=new int[target+1];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=target;j++){
            dp[i][j]=-1;
        }
    }
    cout<<count(n-1,target,arr,dp);

    return 0;
}