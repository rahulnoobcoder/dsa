    #include <bits/stdc++.h>
    using namespace std;


    int power(int x,int n,int dp[]){
        if (n==0){
            return 1;
        }
        if (n==1){
            return x;
        }
        if (dp[n]!=-1) return dp[n];

        int half=power(x,n/2,dp);
        n&1?dp[n]=half*half*x:dp[n]=half*half;

        return dp[n];
    }




    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif

        int x,n;
        cin>>x>>n;

        int dp[n+1];
        for(int i=0;i<=n;i++) dp[i]=-1;
        cout<<power(x,n,dp);
        return 0;
    }