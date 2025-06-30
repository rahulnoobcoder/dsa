#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if (b>0){
        return gcd(b,a%b);
    }
    else{
        return a;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;

    cout<<gcd(n,m);
    
    return 0;
}