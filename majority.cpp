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

    unordered_map<int,int> map;
    for(auto i:v){
        if (map.find(i)!=map.end()){
            map[i]++;
            if (map[i]>n/2){
                cout<<map[i];
                break;
            }
        }
        else{
            map[i]=1;
        }
    }



    return 0;
}