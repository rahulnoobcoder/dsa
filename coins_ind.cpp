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
    vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};
    
    int count = 0;
    int i = 8;
    while(n>0 && i>=0){
        if (n>=coins[i]){
            count = count + n/coins[i];
            n = n - (n/coins[i])*coins[i];  
        }
        i--;
    }

    cout<<count;

    return 0;
}