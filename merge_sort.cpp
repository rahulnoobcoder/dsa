#include <bits/stdc++.h>
using namespace std;
void merge_sort(int arr[],int l,int r){
    if (l<r){
        int mid=l+(r-l)/2;

        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);


        int n1=mid-l+1;
        int n2=r-mid;

        int a[n1],b[n2];

        for(int i=0;i<n1;i++){
            a[i]=arr[l+i];
        }
        for(int i=0;i<n2;i++){
            b[i]=arr[mid+i+1];
        }


        int i=0,j=0,k=l;

        while(i<n1 && j<n2){
            if (a[i] > b[j]){
                arr[k++]=b[j++];
            }
            else{
                arr[k++]=a[i++];
            }
        }
        while(i<n1){
            arr[k++]=a[i++];
        }
         while(j<n2){
            arr[k++]=b[j++];
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
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}