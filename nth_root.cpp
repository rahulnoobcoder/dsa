#include <bits/stdc++.h>
using namespace std;




int sqrt(int n,int l,int r,int m){
    if (l<=r){
        int mid=l+(r-l)/2;
        int k=round(pow(mid,m));
        if (k==n){
            return mid;
        }
        else if (k<n){
            return sqrt(n,mid+1,r,m);
        }
        else{
            return sqrt(n,l,mid-1,m);
        }
    }
    else{
        return -1;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin >> n>>m;
    cout<<sqrt(n,1,n,m);

    return 0;
}