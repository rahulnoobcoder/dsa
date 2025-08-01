#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &v,vector<vector<int>> &ans){
    for(auto i:ans){
        if (i==v){
            return true;
        }
    }
    return false;
}




void print(int arr[],vector<int> &v,int n,int i,vector<vector<int>> &ans){
    if (i==n){
        if (!check(v,ans))
        ans.push_back(v);
        return;
    }

    print(arr,v,n,i+1,ans);

    v.push_back(arr[i]);
    print(arr,v,n,i+1,ans);
    v.pop_back();

}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<vector<int>> ans;
    vector<int> x;
    print(v,x,n,0,ans);

    for(auto i:ans){
        for(auto j:i){
            cout<<j;
        }
        cout<<endl;
    }

    return 0;
}