#include <bits/stdc++.h>
using namespace std;




int solve_only_pos(vector<int> &arr,int k,int n){
    unordered_map<int,int> mp;
    int sum = 0, len = 0;
    
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if (sum == k) len = max(len,i+1);
        
        int rem = sum-k;
        if (mp.find(rem)!=mp.end()){
            len = max(len,i-mp[rem]);
        }
        mp[sum]=i;
    }

    return len;
}


int solve_any(vector<int> &arr,int k,int n){
    unordered_map<int,int> mp;
    int sum = 0, len = 0;
    
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if (sum == k) len = max(len,i+1);
        
        int rem = sum-k;
        if (mp.find(rem)!=mp.end()){
            len = max(len,i-mp[rem]);
        }
        if (mp.find(sum)!=mp.end())
        mp[sum]=i;
    }

    return len;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int len = solve_only_pos(arr,k,n);
    cout<<len<<endl;
    return 0;
}