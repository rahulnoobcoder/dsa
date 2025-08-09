#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int i,int n,int tot_sum,int cost,set<int> &ans){
    if (i==n){
        if (tot_sum!=cost && cost!=0)
        ans.insert(abs(2*cost-tot_sum));
        return;
    }


    solve(arr,i+1,n,tot_sum,cost+arr[i],ans);

    while(i<n-1 && arr[i]==arr[i+1]) i++;
    solve(arr,i+1,n,tot_sum,cost,ans);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int tot_sum=0;
    for(int i=0;i<n;i++){
        tot_sum+=arr[i];
    }

    set<int> ans;
    solve(arr,0,n,tot_sum,0,ans);
    int min_val = *ans.begin();
    cout<<min_val;
    return 0;
}