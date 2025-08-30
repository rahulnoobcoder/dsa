#include <bits/stdc++.h>
using namespace std;

bool flag=false;
void dfs(vector<vector<int>>&g,vector<int> &visited,int i){
    visited[i]=1;
    for(auto j:g[i]){
        if (visited[j]==0){
            dfs(g,visited,j);
        }
        else if (visited[j]==1){
            flag=true;
            return;
        }
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
    }
    vector <int> visited(n,0);
    for(int i=0;i<n;i++){
        if (visited[i]==0){
            dfs(adj,visited,i);
        }
    }

    cout<<flag;
    return 0;
}