#include <bits/stdc++.h>
using namespace std;

int explore(int** arr,int i,int j,int m,int n){
    if(i==m-1 && j==n-1){
        return arr[i][j];
    }
    if(arr[i][j]==-1){
        return INT_MAX;
    }   

    int down=INT_MAX,right=INT_MAX;

    if (i<m-1 && arr[i+1][j]!=-1){
        int temp=explore(arr,i+1,j,m,n);
        if (temp!=INT_MAX)
        down = arr[i][j]+temp;
    }
    if (j<n-1 && arr[i][j+1]!=-1){
        int temp=explore(arr,i,j+1,m,n);
        if (temp!=INT_MAX)
        right = arr[i][j]+temp;
    }

    return min(down,right);
}




int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int m,n;
    cin>> m>>n;

    int **arr=new int*[m];
    for(int i=0;i<m;i++){
        arr[i]=new int[n];
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int k=explore(arr,0,0,m,n);

    if (k==INT_MAX){
        cout<<-1;
    }
    else{
        cout<<k;
    }



    return 0;
}