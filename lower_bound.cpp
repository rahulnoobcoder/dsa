#include <bits/stdc++.h>
using namespace std;


int binary_search(vector<int>v , int l,int r,int k){
    if (l<=r){

        int mid=l+(r-l)/2;
         if (v[mid]<k){
            
            return binary_search(v,mid+1,r,k);   
        }
        else{
            return binary_search(v,l,mid-1,k);
        }
        
    }
    else{
        return l;
    }
}


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
    //stl - lower_bound
    // cout<<lower_bound(v.begin(),v.end(),n)-v.begin()<<endl;
    cout<<binary_search(v,0,n-1,k);

    return 0;
}