#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin >> n>>m;
    vector<int> a(n),b(m);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector <int> ans ;
    int i=0,j=0;
    while(i<n &&  j<m){
        
        if (a[i]<=b[j]){
            ans.push_back(a[i++]);
        }
        else if (a[i]>b[j]){
            ans.push_back(b[j++]);
        }
        while(i<n && a[i]==ans.back()){
        i++;}
        while(j<m && b[j]==ans.back()){
        j++;}
    }

    while(j<m){
        while(j<m && b[j]==ans.back()){
        j++;}
        ans.push_back(b[j++]);
    }

    while(i<n){
        while(i<n && a[i]==ans.back()){
        i++;}
        ans.push_back(a[i++]);
    }


    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}