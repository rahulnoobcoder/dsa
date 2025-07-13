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


    int sum=0;
    int mx=0;
    int i=0;

    while(i<n){
        if ((sum+v[i])<0){
            sum=0;
        }
        else{
            sum=sum+v[i];
            mx=max(sum,mx);
        }
        i++;
    }

    cout<<mx;
    return 0;
}