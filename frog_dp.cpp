#include <bits/stdc++.h>
using namespace std;

int cost(int a,int b){
    return abs(a-b);
}
int solve(int arr[],int i,int n,int dp[]){
    
    if (i==n-2){
        return cost(arr[i],arr[i+1]);
    }
    if (i==n-1){
        return 0;
    }

    if (dp[i]!=-1){
        return dp[i];
    }
    int single = cost(arr[i],arr[i+1])+solve(arr,i+1,n,dp);
    int dble   = cost(arr[i],arr[i+2])+solve(arr,i+2,n,dp); 

    return dp[i]=min(single,dble);

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
    for(int i=0;i<n;i++){
        dp[i]=-1;
    }
    cout<<solve(arr,0,n,dp);

    




    return 0;
}