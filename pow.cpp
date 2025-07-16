#include <bits/stdc++.h>
using namespace std;




// int get_pow(int n,int m,map<long long ,long long > &dp){
//     if (m<=1){
//         dp[m]=n*m;
//         return dp[m];
//     }
    
//     if (dp.find(m)!=dp.end()){
//         return dp[m];
//     }
//     long long l=get_pow(n,m/2,dp);

//     if (m&1){
//         dp[m]=l*l*n;
//     }
//     else{
//         dp[m]=l*l;
//     }

//     return dp[m];


// }

int get_pow(long long x,long long n){
    long long ans=1;

    while(n>0){
        if (n&1){
            ans=ans*x;
            n--;
        }
        else{
            x=x*x;
            n=n/2;
        }
    }

    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;
    map <long long,long long    > mp;

    // cout<<get_pow(n,m,mp);
    cout<<get_pow(n,m);

    return 0;
}