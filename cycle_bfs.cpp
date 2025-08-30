#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // << important

    vector<vector<int>> adj(n,vector<int>(n,0));

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        if (line.empty()) continue; // no outgoing edges
        stringstream ss(line);
        int x;
        while (ss >> x) {
            adj[i][x]=1;
            adj[x][i]=1; // directed edge i -> x
        }
    }
    for(auto i:adj){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vector<int> visited(n,0);
    bool flag=0;
    for(int i=0;i<n;i++){
        if (flag==1) continue;
        if (!visited[i]){
            queue<pair<int,int>> q;
            q.push({i,-1});
            visited[i]=1;
            while(!q.empty()){
                int node=q.front().first;
                int par=q.front().second;
                q.pop();
                for(int j=0;j<adj.size();j++){
                    if (adj[node][j]==1){
                        if (!visited[j]){
                            q.push({j,node});
                            visited[j]=1;
                        }
                        else flag=1;
                            
                    }
                }

            }
        }
    }

    if (flag) cout<<"cycle"<<endl;
    else cout<<"No cycle"<<endl;
    return 0;
}
