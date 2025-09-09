#include <bits/stdc++.h>
using namespace std;
int solve_any(vector<int> &arr,int k,int n){
    int left = 0;
    int sum =0,len=0;
    for (int right = 0; right < n; right++){
        sum = sum + arr[right];
        while  (left<=right && sum > k){
            sum = sum-arr[left++];
        } 
        if (sum == k ){
            len = max(len,right-left+1);
        } 
    }
    return len;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,k;
    cin >> n>>k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout<<solve_any(arr,k,n);
    

    return 0;
}