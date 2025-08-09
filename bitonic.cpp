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
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        int mx=1;
        for(int prev=0;prev<i;prev++){
            if (arr[i]>arr[prev])
            mx=max(mx,dp[prev]+1);
        }
        dp[i]=mx;
    }

    vector<int> dp2(n,1);
    for(int i=n-2;i>=0;i--){
        int mx=1;
        for(int prev=n-1;prev>i;prev--){
            if (arr[i]>arr[prev])
            mx=max(mx,dp2[prev]+1);
        }
        dp2[i]=mx;

    }


    int mx=1;
    for(int i=0;i<n;i++){
        mx=max(mx,dp[i]+dp2[i]-1);
    }
    cout<<mx;
    return 0;
}