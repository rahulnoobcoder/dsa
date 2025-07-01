#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int arr[n];
    unordered_map <int,int> mp; 
    for(int i = 0 ; i<n;i++){
        cin>>arr[i];

        if (mp.find(arr[i])==mp.end()){
            mp[arr[i]]=1;
        }
        else{
            mp[arr[i]]++;
        }
    }
    for(const auto& pair:mp){
        cout<<pair.first<<" : "<<pair.second<<endl;
    }
    return 0;
}