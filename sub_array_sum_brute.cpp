#include <bits/stdc++.h>
using namespace std;

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

    int len=0;

    for(int i=0;i<n;i++){
        int s=0;
        for(int j=i;j<n;j++){
            s=s+v[j];
            if (s==k){
                len=max(len,j-i+1);
                cout<<i<<" "<<j<<endl;
                break;
            }
        }
    }
    cout<<len;

    
    return 0;
}