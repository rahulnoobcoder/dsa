class Solution {
  public:
    bool check(int i,int j,int n,int m){
        return i<n && j<m && i>=0 && j>=0;
    }
    void bfs(vector<vector<char>> &grid,vector<vector<int>> &visited,int i,int j,int n,int m,queue<pair<int,int>> &q){
        q.push({i,j});
        visited[i][j]=1;
        
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){
                    int ni = r+k;
                    int nj = c+l;
                    if (k==0 && l==0) continue;
                    
                    if (check(ni,nj,n,m) && !visited[ni][nj] && grid[ni][nj]=='L'){
                        visited[ni][nj]=1;
                        q.push({ni,nj});
                    }
                }
            }
        }
    }  
  
  
    int countIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (!visited[i][j] && grid[i][j]=='L'){
                    bfs(grid,visited,i,j,n,m,q);
                    count+=1;
                }
            }
        }
        return count;
    }
};