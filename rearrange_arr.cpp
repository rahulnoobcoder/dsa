#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }


    vector<int>arr;


    int pos=0,neg=1;
    int i=0,j=0;
    vector <int> ans(n,0);
    while(pos<n && neg<n){
        while(i<n && v[i]>0){
            i++;
        }
        while(j<n && v[j]<0){
            j++;
        }
        ans[pos]=v[j++];
        ans[neg]=v[i++];
        pos+=2;
        neg+=2;
    }
    
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}