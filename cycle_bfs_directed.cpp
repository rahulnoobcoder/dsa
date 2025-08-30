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

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        if (line.empty()) continue; // no outgoing edges
        stringstream ss(line);
        int x;
        while (ss >> x) {
            adj[i].push_back(x);
        }
    }
    for(auto i:adj){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    
   
    return 0;
}
