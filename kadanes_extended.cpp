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


    int sum=0;
    int mx=0;
    int i=0;
    int st=0,en;
    while(i<n){
        if ((sum+v[i])<0){
            sum=0;
            st=i+1;
            
        }
        else{
            sum=sum+v[i];
            if (sum>mx){
                mx=max(sum,mx);
                en=i;
            }
        }
        i++;
    }

    cout<<mx<<endl;
    cout<<st<<" "<<en<<endl;
    return 0;
}