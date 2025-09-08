#include <bits/stdc++.h>
using namespace std;


void build(vector<pair<int,int>> &segm, vector<int> &arr,int idx,int low,int high){
    if (low == high){
        segm[idx]={arr[low],1};
        return;
    }

    int mid = low + (high - low)/2;
    build(segm,arr,2*idx,low,mid);
    build(segm,arr,2*idx+1,mid+1,high);
    pair<int,int> left = segm[2*idx] ,right = segm[2*idx+1];
    if (left.first == right.first){
        segm[idx] = {left.first,left.second+right.second};
    }
    else{
        if (left.first > right.first){
            segm[idx] = left;
        }
        else{
            segm[idx] = right;
        }
    }
}

pair<int,int> query(vector<pair<int,int>> &segm,int i,int low,int high,int l,int r){
    if (l<=low && r>=high) return segm[i];
    if (r<low || l>high) return {INT_MIN,0};

    int mid = low + (high - low)/2;
    pair <int,int> left = query(segm,2*i,low,mid,l,r), right = query(segm,2*i+1,mid+1,high,l,r);
    if (left.first == right.first){
        return  {left.first,left.second+right.second};
    }
    else{
        if (left.first > right.first){
            return left;
        }
        else{
            return right;
        }
    }
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

    vector<pair<int,int>> segm(4*n,{0,0});

    build(segm,arr,1,0,n-1);

    pair<int,int> ans = query(segm,1,0,n-1,0,1);
    cout<<ans.first<<endl;
    cout<<ans.second<<endl;
    return 0;

}