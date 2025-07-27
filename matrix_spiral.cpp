#include <bits/stdc++.h>
using namespace std;

void printm(vector<vector<int>> & v, int r1,int r2, int c1,int c2){

    if (r1>r2 || c1>c2){
        return;
    }

    for(int i=c1;i<=c2;i++){
        cout<<v[r1][i]<<" ";
    }
    cout<<'a'<<endl;
    for(int i=r1+1;i<r2;i++){
        cout<<v[i][c2]<<" ";
    }
    cout<<'b'<<endl;

    if (r1==r2 or c1==c2){
        return;
    }

    for(int i=c2;i>=c1;i--){
        cout<<v[r2][i]<<" ";
    }
    
    cout<<'c'<<endl;
    for(int i=r2-1;i>r1;i--){
        cout<<v[i][c1]<<" ";
    }
    cout<<'d'<<endl;
    printm(v,r1+1,r2-1,c1+1,c2-1);
}






int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    int x;
    cin >> n>>m;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; ++i) {
        for(int j=0;j<m;j++){
            cin >>x;
            v[i].push_back(x);
        }
    }

    printm(v,0,n-1,0,m-1);
    return 0;
}