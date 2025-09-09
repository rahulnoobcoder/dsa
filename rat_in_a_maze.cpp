#include <bits/stdc++.h>
using namespace std;


void solve(vector<vector<int>> &arr,int i,int j,int n,string &path){
    if (i==n-1 && j==n-1){
        cout<<path<<endl;
        return;
    }
    
    if (i+1<n && arr[i+1][j]==1){
        path.push_back('D');
        solve(arr,i+1,j,n,path);
        path.pop_back();
    }
    if (j+1<n && arr[i][j+1]==1 ){
        path.push_back('R');
        solve(arr,i,j+1,n,path);
        path.pop_back();
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0;j < n;j++)
        cin >> arr[i][j];
    }
    string path;
    solve(arr,0,0,n,path);
    return 0;
}