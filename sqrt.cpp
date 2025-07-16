#include <bits/stdc++.h>
using namespace std;




int sqrt(int n,int l,int r){
    if (l<=r){
        int mid=l+(r-l)/2;
        if (mid==n/mid){
            return mid;
        }
        else if (mid < n/mid){
            return sqrt(n,mid+1,r);
        }
        else{
            return sqrt(n,l,mid-1);
        }
    }
    else{
        return l-1;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    cout<<sqrt(n,1,n);

    return 0;
}