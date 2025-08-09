#include <bits/stdc++.h>
using namespace std;

int count(int i,int target,int coins[],int **dp){
        if (target==0){
            return 0;
        }
        if (i==0){
            return (target=arr[i]);
        }
        if (target<0 || i<0){
            return INT_MAX;
        }
        if (dp[i][target]!=-1) return dp[i][target];
        int take=count(i,target-coins[i],coins,dp);
        if (take!=INT_MAX) take++;
        int ntake=count(i-1,target,coins,dp);

        return dp[i][target]=min(take,ntake);
        
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
    
    int dp[n][target+1];

    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<n;i++){
        for (int j=0;j<=target;j++){
            
            int take=dp[i][target-coins[i]];

        }
    }
    


    return 0;
}