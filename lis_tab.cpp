#include <bits/stdc++.h>
using namespace std;


int lis(int arr[],int n,int curr,int prev,int** dp){
    if (curr==n){
        return 0;
    }

    if (dp[curr][prev+1]!=-1)  return dp[curr][prev+1];

    //ntake
    int take=INT_MIN;
    if (prev==-1 || arr[curr]>arr[prev]){
        take=1+lis(arr,n,curr+1,curr,dp);
    }
    
    int ntake=lis(arr,n,curr+1,prev,dp);
    return dp[curr][prev+1]=max(take,ntake);
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int take=0;
            if (prev==-1 || arr[curr]%arr[prev]==0){
                take=1+dp[curr+1][curr+1];
            }
            int ntake=dp[curr+1][prev+1];
            dp[curr][prev+1]=max(take,ntake);
        }
    }

    int prev=-1;

    for(int curr=0;curr<n;curr++){
        int take = 0, ntake = dp[curr + 1][prev + 1];

    // Only compute `take` if it's a valid division
    if (prev == -1 || arr[curr] % arr[prev] == 0) {
        take = 1 + dp[curr + 1][curr + 1];

        if (take >= ntake) {
            cout << arr[curr] << " ";
            prev = curr;
        }
    }
    }



    cout<<endl;
    cout<<dp[0][0];
    

    return 0;
}