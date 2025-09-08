#include <bits/stdc++.h>
using namespace std;


void merge_sort(vector<int> &arr,int low,int high){
    if (low >= high) return;

    int mid = low + (high-low)/2;

    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);


    int n1 = mid-low+1,n2=high-mid;

    int a[n1],b[n2];

    for(int i=0;i<n1;i++){
        a[i] = arr[low + i];
    } 

    for(int i=0;i<n2;i++){
        b[i] = arr[mid + i + 1];
    }

    int i=0,j=0,k=low;

    while(i<n1 && j<n2){
        if (a[i]>=b[j]){
            arr[k] = b[j];
            j++;
        }
        else {
            arr[k] = a[i];
            i++;
        }
        k++;
    }

    while(i<n1){
        arr[k++] = a[i++];
    }
    while(j<n2){
        arr[k++] = b[j++];
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

    merge_sort(arr,0,n-1);


    for(auto i:arr) cout<<i<<" ";
    return 0;
}