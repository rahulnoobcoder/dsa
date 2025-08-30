#include <bits/stdc++.h>
using namespace std;
bool flag=false;
void dfs(vector<vector<int>> &graph,int i,vector<int> &visited,int parent){
    if (flag) return;
    if (visited[i]) return;
    visited[i]=1;
    for(auto j:graph[i]){
        if (!visited[j]) dfs(graph,j,visited,i);
        else if (j!=parent) flag=true;
    }
}


void dfs_directed(vector<vector<int>> &graph,int i,vector<int> &visited){
    if (flag) return;
    visited[i]=1;
    for(auto j:graph[i]){
        if (visited[j]==1) flag=true;
        else if (visited[j]==0) dfs_directed(graph,j,visited);
    }
    visited[i]=2;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    int x, y;
    while (cin >> x >> y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
        // For undirected graph: adj[y].push_back(x);
    }
    
    vector<int> visited(n,0);
    
    dfs(adj,0,visited,-1);
    cout<<flag<<endl;
}