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

    // map<int,int> map;
    // for(auto i:v){
    //     if (map.find(i)!=map.end()){
    //         map[i]++;
    //         if (map[i]>n/2){
    //             cout<<i;
    //             break;
    //         }
    //     }
    //     else{
    //         map[i]=1;
    //     }
    // }

    //optimal approach

    int ele,count=0;

    for(auto i:v){
        if (count==0){
            ele=i;
            count++;
        }
        else{
            ele==i?count++:count--;
        }
    }   
    cout<<ele;




    return 0;
}