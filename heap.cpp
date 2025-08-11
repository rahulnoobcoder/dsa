#include <bits/stdc++.h>
using namespace std;

void heapify_down(int arr[],int i,int size){
        while(true){
            int largest=i;
            int li=2*i;
            int ri=2*i+1;

            if (li<=size && arr[li] > arr[largest]) largest=li;
            
            if (ri<=size && arr[ri] > arr[largest]) largest=ri;

            if (i!=largest){
                swap(arr[i],arr[largest]);
                i=largest;
            }
            else{
                break;
            }
        }
    }

    void build_heap(int nums[],int size){
        for(int i=size/2;i>=1;i--){
            heapify_down(nums,i,size);
        }
    }


void heap_sort(int arr[],int size){
    build_heap(arr,size);

    for(int i=size;i>1;i--){
        swap(arr[1],arr[i]);
        heapify_down(arr,1,i-1);
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
    int arr[n+1];
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    // build_heap(arr,n);
    heap_sort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }


    

    return 0;
}