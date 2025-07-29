#include <bits/stdc++.h>
using namespace std;

void bin(int arr[],int n,int i){   
    if (n==i){
        for(int j=0;j<n;j++){
            cout<<arr[j];
        }
        cout<<endl;
        return;
    } 
    arr[i]=0;
    bin(arr,n,i+1);
    arr[i]=1;
    bin(arr,n,i+1);

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int arr[n];
    bin(arr,n,0);
    return 0;
}