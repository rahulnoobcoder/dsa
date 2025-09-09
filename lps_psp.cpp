#include <bits/stdc++.h>
using namespace std;
int solve(int i,int j,string s,vector<vector<int>> &dp){
        if (i>j) return 0;
        if (i==j) return 1;
        if (dp[i][j]!=-1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j]=2+solve(i+1,j-1,s,dp);

        return dp[i][j]=max(solve(i+1,j,s,dp),solve(i,j-1,s,dp));
    }
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<solve(0,n-1,s,dp);

    return 0;
}