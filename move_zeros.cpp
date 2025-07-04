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

    int pos=0;

    for (int i=0;i<n;i++){
        if (v[i]!=0){
            v[pos++]=v[i];
            
        }
    }

    while(pos<n){
        v[pos++]=0;
    }
    

    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}