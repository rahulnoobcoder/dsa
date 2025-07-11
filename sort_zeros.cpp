#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int low=0,mid=0,high=n-1;
    
    // while(v[low]==0){
    //     low++;
    // }
    // int mid=low;
    // while(v[mid]==1){
    //     mid++;
    // }
    // int high=n-1;
    
    // while(v[high]==2){
    //     high--;
    // }
    
    while(mid<=high){
        // cout<<low<<endl;
        // cout<<mid<<endl;
        // cout<<high<<endl<<endl;
        if (v[mid]==0){
            swap(v[low],v[mid]);
            low++;mid++;
        }
        else if (v[mid]==2){

            swap(v[mid],v[high]);
            high--;
        }
        else if (v[mid]==1){
            mid++;
        }

    // for(auto i:v){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // }

    for(auto i:v){
        cout<<i<<" ";
    }
    
    return 0;
}