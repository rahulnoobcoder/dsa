#include <bits/stdc++.h>
using namespace std;




int find(int arr[],int i,int n,int ans[]){
    if (i==n-1){
        return arr[i];
    }
    if (i>=n){
        return 0;
    }
    if (ans[i]!=-1){
        return ans[i];
    }
    int take=arr[i]+find(arr,i+2,n,ans);
    int ntake=find(arr,i+1,n,ans);

    return ans[i]=max(take,ntake);
    
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

    int dp[n];
    memset(dp,-1,sizeof(dp));
    cout<<find(arr,0,n,dp);
    return 0;
}