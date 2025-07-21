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

        int i;
        for(i=n-2;i>=0;i--){
            if (v[i]<v[i+1]){
                break;
            }
        }
        if (i==-1){
            for(int i=0;i<n/2;i++){
                swap(v[i],v[n-i-1]);
            }
        }
        else{
            int j=n-1;
            while(v[j]<=v[i]){
                j--;
            }
            swap(v[i],v[j]);
            int l=i+1,r=n-1;
            while(l<r){
                swap(v[l++],v[r--]);
            }
        }

    for(auto i:v){
        cout<<i<<" ";
    }


    return 0;
}