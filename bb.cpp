#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n,j,k;
        cin >>n>>j>>k;
        vector<int> v(n);
        int min=n;
        for(int i = 0; i < n; ++i){
            cin >> v[i];
            if (v[i]<min){
                min=v[i];
            }
        }
        k>1?cout<<"YES"<<endl:v[j-1]==min?cout<<"NO"<<endl:cout<<"YES"<<endl;
    }

    return 0;
}