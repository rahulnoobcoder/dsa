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


    int rev=0;

    int dig;

    while(n>0){
        dig = n%10;
        n=n/10;
        rev=rev*10+dig;
    }

    cout<<rev;
    return 0;
}