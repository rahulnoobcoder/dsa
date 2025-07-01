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


    int fl=0;

    for(int i=2;i<sqrt(n)+1;i++){
        if (n%i==0){

            fl=1;
        }
    }
    n<2?cout<<"not a prime":fl==0?cout<<"prime":cout<<"not a prime";
    
    return 0;
}