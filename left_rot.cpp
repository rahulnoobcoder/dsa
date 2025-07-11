#include <bits/stdc++.h>
using namespace std;

void rev(vector<int> &arr,int l,int r){
    while(l<r){
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,k;
    cin >> n>>k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    k=k%n;
    rev(v,0,k-1);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    rev(v,k,n-1);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    rev(v,0,n-1);

    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}