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
    vector<vector<pair<int,int>>> G(n);
    int edg;
    cin>>edg;
    int u,v,w;
    while(edg--){
        cin>>u>>v>>w;  //x->y with weight z
        G[u].push_back({w,v});
        G[v].push_back({w,u});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> visited(n,0);
    pq.push({0,0});
    int cost = 0 ;
    while(!pq.empty()){ 
        int w = pq.top().first;
        int node  = pq.top().second;
        pq.pop();
        if (!visited[node]){
            cost = cost + w;
            for (auto j:G[node]){
                int nd = j.second;
                if (!visited[nd]){
                    pq.push({j.first,nd});
                }
            }
        }
        visited[node] = 1;
    }
    cout<<cost<<endl;
    return 0;
}