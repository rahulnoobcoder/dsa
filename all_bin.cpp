#include <bits/stdc++.h>
using namespace std;

void bin(int n,int i){
    if (i==n){
        cout<<endl;
    }
    cout<<0;
    bin(n,i+1);
    cout<<1;
    bin(n,i+1);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
   bin(n,0);
    return 0;
}