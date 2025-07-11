#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,t;
    cin >> n>>t;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    unordered_map<int,int> map;
    int f=0;
    for(int i=0;i<n;i++){
        if (map.find(t-v[i])!=map.end()){
            f=1;
            cout<<map[t-v[i]]<<" "<<i<<endl;
            break;
        }
        else{
            map[v[i]]=i;
        }
    }

    if (f==0){
        cout<<-1;
    }


    return 0;
}