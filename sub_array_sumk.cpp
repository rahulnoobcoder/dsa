#include <bits/stdc++.h>
using namespace std;

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

    unordered_map<int,int> mp;
    int sum = 0, len = 0;
    
    for(int i=0;i<n;i++){
        if ( mp.find(k - arr[i])!=mp.end()){
            len=max(len,i-mp[arr[i]]+1);
            sum=0;
        }
        else{
            sum=sum+arr[i];
            mp[arr[i]] = sum;
        }
    }

    cout<<len<<endl;
    return 0;
}