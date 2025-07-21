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

    // vector<int>r;
    // r.push_back(v[n-1]);
    // for (int i=n-2;i>=0;i--){
    //     if (v[i]>r[0])
    //     r.insert(r.begin(),v[i]);
    //     else
    //     r.insert(r.begin(),r[0]);
    // }

    // for(int i=0;i<v.size();i++){
    //     if (v[i]==r[i]){
    //         cout<<v[i]<<" ";
    //     }
    // }

    vector <int> leader; 
    leader.push_back(v[n-1]);
    int m=v[n-1];

    for (int i=n-2;i>=0;i--){
        if (v[i]>m){
            m=v[i];
            leader.insert(leader.begin(),m);
        }
    }


    for(auto i:leader){
        cout<<i<<" ";
    }
    return 0;
}