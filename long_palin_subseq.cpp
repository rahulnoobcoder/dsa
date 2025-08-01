#include <bits/stdc++.h>
using namespace std;


int solve(char arr[],int l,int r,int** dp){
    if (l==r){
        return 1;
    }
    if (l>r){
        return 0;
    }

    if (dp[l][r]!=-1){
        return dp[l][r];
    }
    
    if (arr[l]==arr[r]){
        return 2+solve(arr,l+1,r-1,dp);
    }


    return dp[l][r] = max(solve(arr,l+1,r,dp),solve(arr,l,r-1,dp));
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int n;
    cin>>n;

    char arr[n+1];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ** dp=new int*[n];

    for(int i=0;i<n;i++){
        dp[i]= new int[n];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }


    cout<<solve(arr,0,n-1,dp);
    return 0;
}