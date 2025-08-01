#include <bits/stdc++.h>
using namespace std;



void sum_(int arr[],int n,int i,int sum,vector<int> &v){
    if (sum==0){
        for(auto j:v){
            cout<<j<<" ";
        }
        cout<<endl;
        return;
    }
    if (i==n || sum<0){
        return;
    }

    v.push_back(arr[i]);
    sum_(arr,n,i+1,sum-arr[i],v);
    v.pop_back();
    
    while(i<n &&  arr[i]==arr[i+1])
    i++;
    sum_(arr,n,i+1,sum,v);  
} 



int count(int arr[],int n,int i,int sum){
    if (sum==0){
        return 1;
    }
    if (i==n || sum<0){
        return 0;
    }

    
    int take=count(arr,n,i+1,sum-arr[i]);    
    while(i<n &&  arr[i]==arr[i+1])
    i++;
    int ntake=count(arr,n,i+1,sum); 
    
    return take+ntake;
} 



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,sum;
    cin >> n>>sum;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if (arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }

    vector<int>v;

    sum_(arr,n,0,sum,v);


    cout<<count(arr,n,0,sum);
    return 0;
}