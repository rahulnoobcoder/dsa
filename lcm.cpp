#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int test_case;
    cin>>test_case;
    for(int t=0;t<test_case;t++){
        int l,r;
        cin>>l>>r;
        int k=l+r;
        if (k%4!=0){
            k=k-(k)%4;
        }
        cout<<(k)/4<<" "<<(k)/2<<endl;
        
    } 
    return 0;
}