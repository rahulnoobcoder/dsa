#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int arr[n];
    int total=0;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        total+=arr[i];
    }
    bool dp[n][total+1];
    memset(dp, 0 , sizeof(dp));
    for(int i=0;i<total+1;i++){
        dp[0][i]=1;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<=total;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}