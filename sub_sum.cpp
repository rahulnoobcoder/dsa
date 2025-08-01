#include <bits/stdc++.h>
using namespace std;




void subsets(int arr[],int i,int n,int sum){
    if (i==n){
        cout<<sum<<" ";
        return;
    } 

    //take
    subsets(arr,i+1,n,sum+arr[i]);

    //ntake
    subsets(arr,i+1,n,sum);
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

    subsets(arr,0,n,0);

    return 0;
}