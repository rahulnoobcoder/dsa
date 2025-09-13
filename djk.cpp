#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
    // V = number of vertices
    // adj[u] = vector of {v, weight} pairs

   vector <int> dis(V,INT_MAX);
   dis[src]=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

   pq.push({0,src});
   while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();

        for (auto nd:adj[node]){
            int m = nd.first;
            int cost = nd.second; 
            if (dis[node]+cost < dis[m]){
                dis[m] = dis[node]+cost;
                pq.push({dis[m],m});
            }
        }
   }
   return dis;
}

int main() {
    int V = 5; // number of vertices
    vector<vector<pair<int,int>>> adj(V);

    // Example graph
    // edge u -> v with weight w
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 3});
    adj[1].push_back({2, 2});
    adj[1].push_back({4, 4});
    adj[2].push_back({3, 9});
    adj[3].push_back({2, 7});
    adj[4].push_back({1, 1});
    adj[4].push_back({2, 8});
    adj[4].push_back({3, 2});

    int src = 0;
    vector<int> dist = dijkstra(V, adj, src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << dist[i] << "\n";
    }

    return 0;
}
