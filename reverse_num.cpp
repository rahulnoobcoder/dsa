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

    int exp=0;
    int dig;
    int count=int(log10(n)+1);

    while(n>0){
        dig = n%10;
        n=n/10;
        rev+=dig*pow(10,count-exp-1);
        exp++;
    }

    cout<<rev;
    return 0;
}