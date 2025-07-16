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
    vector<vector<int>> adj(n);
    int x, y;
    while (cin >> x >> y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
        // For undirected graph: adj[y].push_back(x);
    }

    

    vector <int> visited(n,0);
    queue <int> q;

    q.push(0);
    while(!q.empty()){
        for(auto i:adj[q.front()]){
            if(visited[i]==0)
            q.push(i);
            visited[i]=1;
        }

        cout<<q.front()<<" ";
        visited[q.front()]=1;
        q.pop();
    }

    cout<<endl;
    
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }



    
    

    return 0;
}