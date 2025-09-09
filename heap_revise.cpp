#include <bits/stdc++.h>
using namespace std;

void heapify_down(vector<int> &arr,int i,int n){
    int l = 2*i;
    int r = 2*i+1;
    int largest = i;

    if (l<=n && arr[l]>arr[largest]){
        largest = l;
    }
    if (r<=n && arr[r] > arr[largest]){
        largest = r;
    }
    if (largest != i){
        swap(arr[i],arr[largest]);
        heapify_down(arr,largest,n);
    }
}


void build_heap(vector<int> &arr,int n){
    for(int i=n/2;i>=1;i--){
        heapify_down(arr,i,n);
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
    vector<int> arr(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    build_heap(arr,n);

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}