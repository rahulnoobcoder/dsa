#include <bits/stdc++.h>
using namespace std;

void build(vector<int> &segm,vector<int> &arr,int index,int low,int high){
    if (low==high){
        segm[index]=arr[low];
        return;
    }

    int mid = low + (high - low)/2;
    build(segm,arr,2*index,low,mid);
    build(segm,arr,2*index+1,mid+1,high);

    segm[index] = segm[2*index]+segm[2*index+1];
}


int query(vector<int> &segm,int index,int low,int high,int l,int r){
    //l ....................r
    //......low..high......          this is complete overlap return node value
    if (l <= low && high <= r) return segm[index];
    // no overlap ......l...r................
            //    .............low..high.....
    if (l>high || r<low ) return 0;

    int mid = low + (high-low)/2;
    int left = query(segm,2*index,low,mid,l,r);
    int right = query(segm,2*index+1,mid+1,high,l,r);
    return left+right;
}

void update(vector<int> &segm, int index, int low, int high, int pos, int val) {
    if (low == high) {
        segm[index] = val;
        return;
    }
    int mid = low + (high - low) / 2;
    if (pos <= mid) 
        update(segm, 2*index, low, mid, pos, val);
    else 
        update(segm, 2*index+1, mid+1, high, pos, val);
    segm[index] = segm[2*index] + segm[2*index+1];
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
    
    cout<<query(segm,1,0,n-1,0,1);
    return 0;
}