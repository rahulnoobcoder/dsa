#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    int x;
    cin >> n>>m;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; ++i) {
        for(int j=0;j<m;j++){
            cin >>x;
            v[i].push_back(x);
        }
    }

    set<int> row,col;

    



    return 0;
}