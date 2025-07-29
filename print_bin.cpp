#include <bits/stdc++.h>
using namespace std;


void print_bin(int l,int i,int n){
    if (i==l){
        return;
    }
    for(int j=n-1;j>=0;j--){
        cout<<((i>>j)&1);
    }
    cout<<endl;
    print_bin(l,i+1,n);

}





int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int l=1<<n;
    print_bin(l,0,n);
    return 0;
}