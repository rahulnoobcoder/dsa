#include <bits/stdc++.h>
using namespace std;


int lis(int arr[],int n,int curr,int prev,vector<int>&v,int ml){
    if (curr==n){
        return ml==v.size();
    }


    //ntake 
    int take=0;
    if (prev==-1 || arr[curr]>arr[prev]){
        v.push_back(arr[curr]);
        take=lis(arr,n,curr+1,curr,v,ml);
        v.pop_back();
    }
    
    int ntake=lis(arr,n,curr+1,prev,v,ml);
    return take+ntake;
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
    int m=1;
    fill(dp,dp+n,1);
    for(int i=1;i<n;i++){
        int mx=1;
        for(int prev=0;prev<i;prev++){
            if (arr[i]>arr[prev])
            mx=max(mx,dp[prev]+1);
        }
        dp[i]=mx;
        m=max(m,dp[i]);
    }
    vector<int> v;
    cout<<lis(arr,n,0,-1,v,m);

    return 0;
}