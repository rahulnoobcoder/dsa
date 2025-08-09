#include <bits/stdc++.h>
using namespace std;

int max_substring(int i,int j,char arr[],char brr[],int cnt){
    if (i<0 || j<0){
        return cnt;
    }

    int res=0;
    if (arr[i]==brr[j]) res =  max_substring(i-1,j-1,arr,brr,cnt+1);

    int a=max_substring(i-1,j,arr,brr,0);
    int b=max_substring(i,j-1,arr,brr,0);

    return max({res,a,b});
}




int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin >>n>>m;
    char arr[n+1],brr[m+1];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> brr[i];
    }

    cout<<max_substring(n-1,m-1,arr,brr,0);

    return 0;
}