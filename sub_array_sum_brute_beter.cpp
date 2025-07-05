#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,k;
    cin >> n>>k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    unordered_map<long long,int>mp;
    int sum=0;
    int max_len=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        if (sum==k)
        max_len=max(max_len,i+1);

        if (mp.find(sum-k)!=mp.end()){
            max_len=max(max_len,i-mp[sum-k]);
        }
        if (mp.find(sum)==mp.end())
        mp[sum] = i;
    }

    cout<<max_len;
    return 0;
}