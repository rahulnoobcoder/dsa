#include <bits/stdc++.h>
using namespace std;
struct KeyHash {
    size_t operator()(const tuple<int,int,int>& t) const {
        // auto [a,b,c] = t;
        int a = get<0>(t);
        int b = get<1>(t);
        int c = get<2>(t);
        // simple hash combining
        return ((size_t)a * 1315423911u) ^ ((size_t)b << 21) ^ ((size_t)c * 2654435761u);
    }
};

int solve(vector<int> &arr,int i,int n,int tot_sum,int cost,int count,unordered_map<tuple<int,int,int>,int,KeyHash> &mp){
    if (count==n/2){
        return abs(2*cost-tot_sum);
    }
    if(count>n/2){
        return INT_MAX;
    }   
    if (i==n){
        return INT_MAX;
    }
    if (mp.find({i,count,cost})!=mp.end()) return mp[{i,count,cost}];
    int take=solve(arr,i+1,n,tot_sum,cost+arr[i],count+1,mp);
    int ntake=solve(arr,i+1,n,tot_sum,cost,count,mp);
    return mp[{i,count,cost}]=min(take,ntake);
    }   
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int tot_sum=0;
    for(int i=0;i<n;i++){
    tot_sum+=nums[i];
    }
    unordered_map<tuple<int,int,int>,int,KeyHash> dp;
    sort(nums.begin(),nums.end());
    cout<<solve(nums,0,n,tot_sum,0,0,dp);
    return 0;
}