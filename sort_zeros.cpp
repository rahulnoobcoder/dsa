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
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int low=0;
    
    while(v[low]==0){
        low+=1;
    }
    cout<<low-1<<endl;
    int mid=low;
    while(v[mid]==1){
        mid+=1;
    }

    cout<<mid-1<<endl;
    return 0;
}