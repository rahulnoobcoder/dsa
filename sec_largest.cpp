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

    int m1,m2;
    v[0]>v[1]?(m1=v[0],m2=v[1]):(m1=v[1],m2=v[0]);
    for(int i=2;i<n;i++){
        if (v[i]>m1){
            m2=m1;
            m1=v[i];
        }
        else if (v[i]>m2){
            m2=v[i];
        }
    }
    cout<<m2;
    return 0;
}