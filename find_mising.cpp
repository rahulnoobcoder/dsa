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
    vector<int> v(n-1);
    int sum=0;
    for(int i = 0; i < n-1; ++i) {
        cin >> v[i];
        sum+=v[i];
    }

    cout<<n*(n+1)/2-sum;

    return 0;
}