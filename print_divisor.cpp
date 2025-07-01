#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;


    for(int i=1;i<sqrt(n)+1;i++){
        if (n%i==0){
            cout<<i<<" "<<n/i<<endl;
        }
    }
    return 0;
}