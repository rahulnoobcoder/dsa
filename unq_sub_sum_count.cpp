#include <bits/stdc++.h>
using namespace std;


int count(int arr[],int i, int target){
    if (target==0){
        return 1;
    }
    if (i<0){
        return 0;
    }

    if (i==0) return target==arr[0];
    int take= count(arr,i-1,target-arr[i]);
    while(i>0 &&  arr[i]==arr[i-1]) i--;
    int ntake=count(arr,i-1,target);

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
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int dp[n][target+1];
    sort(arr,arr+n);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    if (arr[0] <= target) dp[0][arr[0]] = 1;
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int take=j >=arr[i] ? dp[i-1][j-arr[i]]:0;
            int ntake=dp[i-1][j];
            dp[i][j]=take+ntake;
        }
    }







    for(int i=0;i<n;i++){
        for(int j=0;j<target+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}