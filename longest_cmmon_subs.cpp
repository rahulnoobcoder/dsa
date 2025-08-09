#include <bits/stdc++.h>
using namespace std;

int lcs(char arr[],char brr[],int i,int j){
    if (i<0 || j<0){
        return 0;
    }
    

    if (arr[i]==brr[j]) return 1+lcs(arr,brr,i-1,j-1);

    return max(lcs(arr,brr,i-1,j),lcs(arr,brr,i,j-1));
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin >>n>>m;
    char arr[n+1],brr[m+1];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> brr[i];
    }
    int st=-1,end=-1;

    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (arr[i-1]==brr[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}