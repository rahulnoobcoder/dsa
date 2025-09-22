#include <bits/stdc++.h>
using namespace std;

class disjoint_set{
    vector<int> rank,parent;
    public:
    disjoint_set(int n){
        rank.resize(n,0);
        parent.resize(n);
        for (int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find_set(int node){
        if (node == parent[node]){
            return node;
        }

        return parent[node] = find_set(parent[node]);
    }

    void union_set(int a,int b){
        int u = find_set(a);
        int v = find_set(b);

        if (u==v) return;

        if (rank[u] < rank[v]){
            parent[u]=v;
        }
        else if (rank[v] < rank[u]){
            parent[v]=u;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
};



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    disjoint_set d(n);
    int edg;
    cin>>edg;
    int u,v,w;
    vector<pair<int,int>> mst;
    vector<vector<int>> edges;
    while(edg--){
        cin>>u>>v>>w;  
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    int cost = 0;
    for (auto edge : edges){
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (d.find_set(u)!=d.find_set(v)){
            mst.push_back({u,v});
            cost = cos  t + w;
            d.union_set(u,v);
        } 
    }

    cout<<cost<<endl;
    for(auto edge: mst){
        cout<<edge.first<<"->"<<edge.second<<endl;
    }
    return 0;
}