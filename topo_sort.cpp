#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &g,vector<int> &visited,int i,stack<int> &s){
    visited[i]=1;
    for(auto j:g[i]){
        if (!visited[j]){ 
            dfs(g,visited,j,s);
        }
    }
    s.push(i);
}


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
    while(m--){
        cin>>x>>y;
        v[x].push_back(y);
    }
    stack<int> s;
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if (!visited[i]) {
            dfs(v,visited,i,s);
        }
    }

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}