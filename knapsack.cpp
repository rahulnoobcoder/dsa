#include <bits/stdc++.h>
using namespace std;

int knap(int i,int weight[],int prof[],int cap){
    if (i==0){
        if (weight[i]<=cap){
            return prof[i];
        }
        return 0;
    }


    int take=0;
    if (weight[i] <= cap){
        take=prof[i]+knap(i-1,weight,prof,cap-weight[i]);
    }
    int ntake=knap(i-1,weight,prof,cap);

    return max(take,ntake);
}





int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,w;
    cin >> n>>w;
    int prof[n];
    int weight[n];
    for(int i = 0; i < n; ++i) {
        cin >> prof[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> weight[i];
    }


    cout<<knap(n-1,weight,prof,w);

    return 0;
}