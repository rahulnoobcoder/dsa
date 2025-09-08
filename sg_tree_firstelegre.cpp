#include <bits/stdc++.h>
using namespace std;

void build(vector<int> &segm,vector<int>&arr,int i,int low,int high){
    if (low == high){
        segm[i] = arr[low];
        return ;
    }

    int mid = low + (high - low)/2;

    build(segm,arr,2*i,low,mid);
    build(segm,arr,2*i+1,mid+1,high);

    segm[i] = max(segm[2*i],segm[2*i+1]);
}


int query(vector<int> &segm,int i,int low,int high,int l,int r,int x){    //returns 1 based index, sub 1 to get exact index in the array 
    
    if (r<low || l>high) return -1;
    if (segm[i] <= x) return -1;

    if (low == high) return low;
    int mid = low + (high - low )/2;

    int left = query(segm,2*i,low,mid,l,r,x);
    if (left !=-1) return left;
    int right = query(segm,2*i+1,mid+1,high,l,r,x);
    return right;

}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> segm(4*n);
    build(segm,arr,1,0,n-1);

    cout<<query(segm,1,0,n-1,0,4,2);
    return 0;
}