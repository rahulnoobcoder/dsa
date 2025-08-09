#include <bits/stdc++.h>
using namespace std;



bool subset(int arr[],int i,int n,int sum,int** dp){
    if (sum==0){
        return true;
    }

    if (i==n || sum<0){
        return false;
    }
    if (dp[i][sum]!=-1){
        return dp[i][sum];
    }
    bool ntake=subset(arr,i+1,n,sum,dp);
    bool take= subset(arr,i+1,n,sum-arr[i],dp);
    return dp[i][sum]= take || ntake;
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,sum;
    cin >> n>>sum;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int** dp=new int*[n];
    for(int i=0;i<n;i++){
        dp[i]=new int[sum+1];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=-1;
        }
    }
    cout<<subset(arr,0,n,sum,dp);
    return 0;
}