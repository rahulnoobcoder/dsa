#include <bits/stdc++.h>
using namespace std;



void print_perms(vector<int> &v,int i,int n){
    if (i==n){
        cout<<"\n";
        return;
    }
    cout<<v[0]<<" ";
    print_perms(v,i+1,n);
}


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

    for(int i=0;i<n;i++){
        swap(v[i],v[0]);
        pritnt_perms(v,0,n);
    }


    return 0;
}