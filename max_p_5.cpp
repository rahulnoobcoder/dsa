#include <bits/stdc++.h>
using namespace std;

void insert(int arr[],int k,int &n){
    int i=0;
    while(i<n && arr[i]<k){
        i++;
    }
    for(int j=n;j>i;j--){
        arr[j]=arr[j-1]; 
    }
    n++;
    arr[i]=k;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,k;
    cin >> n>>k;
    int arr[10]={1,2,4,5};
    int c=4;
    insert(arr,k,c);
    cout<<c<<endl;

    for(int i=0;i<c;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}