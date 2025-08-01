#include <bits/stdc++.h>
using namespace std;


int check(char arr[],int i,int j){
    if (i==j){
        return 1;
    }
    if (i>j){
        return 0;
    }

    if (arr[i]==arr[j]){
        return 2+check(arr,i+1,j-1);
    }

    int le=check(arr,i+1,j);
    int re=check(arr,i,j-1);

    return max(le,re);
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    char arr[n+1];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<check(arr,0,n-1);
    return 0;
}