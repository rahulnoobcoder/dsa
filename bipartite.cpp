#include <bits/stdc++.h>
using namespace std;

int flag=0;
void cycle(vector<vector<int>>&v,vector<int> &visited,int i){
        queue<tuple<int,int,int>> q;
        unordered_map<int,int> level;
        q.push({i,-1,0});
        level[i]=0;
        visited[i]=1;
        while(!q.empty()){
            auto t = q.front();
            int node = get<0>(t);
            int parent = get<1>(t);
            int dis = get<2>(t);
            q.pop();
            for(auto j:v[node]){
                if (!visited[j]) {
                    q.push({j,node,dis+1});
                    level[j]=dis+1;
                    visited[j]=1;
                }
                else if (j!=parent){
                    if (abs((level[j]-level[node]))%2==0){
                        flag=1;
                        return;
                    }
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

    cin>>n>>m;

    vector<vector<int>> G(n);
    int x,y;
    while(m--){
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if (!visited[i]){
            cycle(G,visited,i);
        }
    }

    cout<<flag;
    return 0;
}