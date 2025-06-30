#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int m=n;
    int count=int(log10(n))+1;
    int l,r;
    for (int i=0;i<count/2;i++){
        l= n/(int(pow(10,count-i-1)));
        n=n%(int(pow(10,count-i-1)));
        r=m%10;
        m=m/10;
        if (l!=r){
            cout<<"not_palindrome"<<endl;
            exit(0);
        }
    }

    cout<<"palindrome"<<endl;





    return 0;
}