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


    vector<int> prime(n+1,1);

    for(auto i:prime){
        cout<<i<<" ";
    }



    return 0;
}