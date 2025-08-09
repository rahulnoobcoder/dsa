#include <bits/stdc++.h>
using namespace std;


int lis(int arr[],int i,int n,int mx,vector<int> &v,bool pick[]){
    if (i==n){
        return 0;
    }



    //take

    int take=INT_MIN,ntake=INT_MIN;
    if (arr[i]>=mx && arr[i]%mx==0){
        take=1+lis(arr,i+1,n,arr[i],v,pick);
    }
    ntake=lis(arr,i+1,n,mx,v,pick);
    pick[i]= take > ntake ;
    return max(take,ntake);
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
    sort(arr,arr+n);
    vector<int> v;
    bool pick[n];
    cout<<lis(arr,0,n,1,v,pick)<<endl;
    for(int i=0;i<n;i++){
        if (pick[i]) {
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;


    return 0;
}