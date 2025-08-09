#include <bits/stdc++.h>
using namespace std;
void uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = min(m - 1, n - 1);
        long long res = 1;

        for (int i = 1; i <= r; ++i) {
            res = res * (N - r + i) / i;
        }
        cout<<res;
    }
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int m,n;
    cin>>m>>n;

    uniquePaths(m,n);

    return 0;
}