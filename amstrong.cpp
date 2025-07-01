#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    int m=n;
    int s=0;
    int count=int(log10(n))+1;
    int dig;
    while(n>0){
        dig=n%10;
        s=s+int(pow(dig,count)+0.5);
        n=n/10;
    }
    s==m?cout<<"YES":cout<<"NO";
    return 0;
}