#include <bits/stdc++.h>
using namespace std;


int cost(vector<int>& h,int n,vector<int>&dp){
        if (n<=1){
            
            return dp[n] = abs(h[n]-h[0]);
        }
        if (dp[n]!=-1){
            return dp[n];
        }
        
        int l=cost(h,n-2,dp)+abs(h[n-2]-h[n]);
        int r=cost(h,n-1,dp)+abs(h[n-1]-h[n]);
        dp[n]=min(l,r);
        return dp[n];
        
    }

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> dp (n,-1);


    cout<<cost(v,n-1,dp);
    return 0;
}