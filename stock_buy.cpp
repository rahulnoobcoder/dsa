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

    int mx_r=0;
    int mx_prof=0;
    for(int i=n-1;i>=0;i--){
        mx_r=max(mx_r,v[i]);
        mx_prof=max(mx_prof,mx_r-v[i]); 
    }
    
    cout<<mx_prof;
    return 0;
}