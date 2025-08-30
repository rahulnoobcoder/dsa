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
    vector<int> visited(n,0);
    queue<int> q;

    for(int i=0;i<n;i++){
        if (!indeg[i]) q.push(i);
    }
    vector<int> order;
    while(!q.empty()){
        int node=q.front();
        for(int i=0;i<n;i++){
            if (g[node][i]==1 && indeg[i]>0){
                indeg[i]--;
            }
            else if (indeg[i]==0) q.push(i);
        }
        order.push_back(node);
        q.pop();
    }

    for(auto i:order) cout<<i<<" ";
    return 0;
}