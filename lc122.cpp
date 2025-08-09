#include <bits/stdc++.h>
using namespace std;

int buy_sell(int i,int buy,int arr[],int n){
    if (i==n){
        return 0;
    }
    int t=0,nt=0;
    if (buy){
        t=-arr[i]+buy_sell(i+1,0,arr,n);
        nt=buy_sell(i+1,1,arr,n);
    }
    else{
        return max(arr[i]+buy_sell(i+1,1,arr,n),buy_sell(i+1,0,arr,n));
    }

    return max(t,nt);

}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout<<buy_sell(0,1,arr,n);

    return 0;
}