#include <bits/stdc++.h>
using namespace std;

int main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;


    int count=0;
    // while(n>0){
    //     n=n/10;
    //     count+=1;
    // }
    

    //optimal 
    int count = int(log10(n)+1)

    cout<<count;
    return 0;
}