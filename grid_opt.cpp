// You are given an m × n grid of integers. Your goal is to find the path with the 
// minimum total cost from the top-left cell (0, 0) to the bottom-right cell (m-1, n-1). 
 
// Each cell in the grid contains either: 
// A non-negative integer (≥ 0) representing the cost to enter that cell. 
// A value of -1 indicates an obstacle that you cannot pass through. 
 
// At any point, you are only allowed to move down or right. The total cost of a 
// path is the sum of the costs of all cells on that path, including the start and end 
// cells. If no valid path exists from the start to the end, the result should be -1. 



#include <bits/stdc++.h>
using namespace std;


int solve(int **arr,int i,int j,int m,int n,int cost){
    if(i==m-1 && j==n-1){
        return cost+arr[i][j];
    }

    int down,right;
    down=right=INT_MAX;

    if(arr[i][j]==-1){
        return INT_MAX;
    }

    if (i<m-1 && arr[i+1][j]!=-1){
        down = solve(arr,i+1,j,m,n,cost+arr[i][j]);
    }
    if (j<n-1 && arr[i][j+1]!=-1){
        right = solve(arr,i,j+1,m,n,cost+arr[i][j]);
    }

    return min(down,right);
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>m>>n;
    int **arr = new int*[m];
    for(int i=0;i<m;i++){
        arr[i]=new int[n];
    }

    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }


    int k= solve(arr,0,0,m,n,0);

    k==INT_MAX?cout<<-1:cout<<k;
    return 0;
}