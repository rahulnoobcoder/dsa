#include <bits/stdc++.h>
using namespace std;

bool flag=false;



void dfs(vector<vector<int>> &v,int i,vector<int> &visited){
    if (visited[i]) return;
    if (flag) return;

    visited[i]=1;

    for(int j=0;j<visited.size();j++){
        if (v[i][j]==1){ 
            if (visited[j]==1) flag=true;
            else dfs(v,j,visited);
        }

    }
    visited[i]=2;
}


void dfs_undir(vector<vector<int>> &v,int i,vector<int> &visited,int parent){
    if (visited[i]) return;
    if (flag) return;

    visited[i]=1;

    for(int j=0;j<visited.size();j++){
        if (v[i][j]==1){ 
            if (!visited[j]) {
                dfs_undir(v, j, visited,i);
            } 
            else if (j != parent) { 
                // back edge not to parent → cycle
                flag = true;
                return;
            }
        }

    }
}




int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin >> n>>m;
    
    int x,y;

    vector<vector<int>> gp(n,vector<int>(n,0));

    while(m--){
        cin>>x>>y;
        gp[x][y]=1;
    }

    vector<int> visited(n,0);

    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(gp,i,visited);
        }
    }
    cout<<flag;

    return 0;
}