#include <bits/stdc++.h>
using namespace std;



int solve(vector<int> &arr,int k){
    unordered_map<int,int> mp;
    int n = arr.size();
    for(int i=0;i<n;i++){
        mp[arr[i]%k]++;
    }

    // for(auto item:mp) cout<<item.first<<":"<<item.second<<" ";
    // cout<<endl;

    int total_ways = 0 ;
    int th =0 ;
    for(auto item:mp){
        int val = item.first;
        int freq = item.second;

        if (val == 0){
            total_ways = total_ways + freq*(freq-1)/2;
        }
        else if (val == k-val){
            total_ways = total_ways + (freq*(freq-1))/2;
        }
        else {
            if (mp.find(k-val)!=mp.end()){
                int fre2 = mp[k-val];
                th += (freq*fre2); 
                
            }
        }
    }
    total_ways += th/2;
    return total_ways;

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout<<solve(arr,k)<<endl;

    }
    return 0;
}