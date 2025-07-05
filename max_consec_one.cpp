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

    int mx=0;
    int count=0;
    for(auto i:v){
        if (i==1){
            count+=1;
        }
        else{
            mx=max(mx,count);
            count=0;
        }
    }
    mx=max({mx,count});

    cout<<mx;
    return 0;
}