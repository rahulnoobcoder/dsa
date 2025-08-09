#include <bits/stdc++.h>
using namespace std;

int cat(int n){
    if (n==0){
        return 1;
    }

    int s=0;
    for(int i=0;i<n;i++){
        s=s+cat(i)*cat(n-i-1);
    }

    return s;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    cout<<cat(n);

    return 0;
}