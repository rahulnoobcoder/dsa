#include <bits/stdc++.h>
using namespace std;

void print(int arr[],int i,int n,vector<int> &v){
    if (i==n){
        for(auto i:v){
            cout<<i;
        }
        cout<<endl;return;
    }

    
    
    v.push_back(arr[i]);
    print(arr,i+1,n,v);
    v.pop_back();

    while(i<n-1 && arr[i]==arr[i+1]) i++;
    print(arr,i+1,n,v);
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
    vector<int> v;
    print(arr,0,n,v);

    return 0;
}