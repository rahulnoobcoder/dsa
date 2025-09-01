#include <bits/stdc++.h>
using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin >> n>> m;
    int x,y;
    vector<vector<int>> v(n);
    vector<int> indeg(n,0);
    while(m--){
        cin>>x>>y;
        v[x].push_back(y);
        indeg[y]++;
    }
    queue<int> q;

    for(int i=0;i<n;i++){
        if (!indeg[i]) q.push(i);
    }
    vector<int> order;
    while(!q.empty()){
        int node=q.front();
        for(auto i:v[node]){
            if (indeg[i]>0){
                indeg[i]--;
            }
            if (indeg[i]==0) q.push(i);
        }
        order.push_back(node);
        q.pop();
    }

    for(auto i:order) cout<<i<<" ";`
    return 0;
}