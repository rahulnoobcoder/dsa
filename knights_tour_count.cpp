#include <bits/stdc++.h>
using namespace std;

int check (int i,int j,int n){
    return i>=0 && j>=0 && i<n && j<n;
}


bool flag = 0 ;
void knight_tour(vector<vector<int>> &grid,int i,int j,int n,int curr,int &count,set<vector<vector<int>>> &s){
    // if (flag) return;
    if (curr == (n*n)) {
        // for(auto i:grid){
        //     for(auto j:i) cout<<j<<" ";
        //     cout<<endl;
        // }
        // flag = 1;
        s.insert(grid);
        count = s.size();
        return;
    }
    int dx[8] = {-1,-1,-2,-2,1,1,2,2};
    int dy[8] = {+2,-2,+1,-1,+2,-2,+1,-1};

    for(int k=0;k<8;k++){
        int new_x = i + dx[k];
        int new_y = j + dy[k];
        if (!check(new_x,new_y,n)) continue;
        if (grid[new_x][new_y]==-1){
            grid[new_x][new_y] = curr;
            knight_tour(grid,new_x,new_y,n,curr+1,count,s);
            grid[new_x][new_y] = -1;
        }
    }
}



int main()  
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int n;
    cin >> n;
    int count =0;
    vector<vector<int>> grid(n,vector<int> (n,-1));
    set<vector<vector<int>>> s;
    grid[0][0]=0;
    knight_tour(grid,0,0,n,1,count,s);
    cout<<count<<endl;
    return 0;
}