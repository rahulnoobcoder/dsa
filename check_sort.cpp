#include <bits/stdc++.h>
using namespace std;


int check(vector <int> &v){
    
    for(int i=0;i<v.size()-1;i++){
        if (v[i+1]<v[i]){
            return 0;
        }
    }
    return 1;
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

    check(v)==1?cout<<"sorted":cout<<"not sorted";

    return 0;
}