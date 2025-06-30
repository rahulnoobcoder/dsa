#include <bits/stdc++.h>
using namespace std;


int gcd(int a,int b){
    if (b>0){
        return gcd(b,a%b);
    }
    else{
        return a;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int a,b;
    cin>>a>>b;


    int hcf=gcd(a,b);

    cout<<hcf<<endl;

    int rem;

    a>b?rem=a%b:rem=b%a;

    int x,y;
    x= hcf/rem;

    a>b?y=(a*x-hcf)/b:y=(b*x-hcf)/a;

    cout<<" x =  "<<x<<", y = "<<-1*y<<endl;






    return 0;
}