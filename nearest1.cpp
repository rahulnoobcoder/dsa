#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &grid, int i, int j, int n, int m) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<pair<int,int>,int>> q; // ((r,c), dist)
    if (grid[i][j]) return 0;
    q.push({{i,j},0});
    visited[i][j] = 1;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto node = q.front().first;
        int r = node.first;
        int c = node.second;
        int d = q.front().second;
        q.pop();

        // skip the starting cell itself
        if (!(r == i && c == j) && grid[r][c] == 1) {
            return d;
        }

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                q.push({{nr, nc}, d+1});
            }
        }
    }
    return -1; // no 1 found
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> gp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> gp[i][j];
        }
    }

    cout << bfs(gp, 0, 0, m, n);
    return 0;
}
