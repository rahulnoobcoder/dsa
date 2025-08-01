#include <bits/stdc++.h>
using namespace std;
void generate_triplets(int arr[],int n){
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                cout<<arr[i]<<arr[j]<<arr[k]<<endl;
            }
        }
    }
}
void print(int arr[],int n,int i) {
    if (i==n){

        cout<<"perm is : "; 
        for(int j=0;j<i;j++){
            cout<<arr[j];
        }
        cout<<endl;
        cout<<"triplets : \n";
        generate_triplets(arr,n);
        cout<<endl;
        return;
    }


    for(int j=i;j<n;j++){
        swap(arr[i],arr[j]);
        print(arr,n,i+1);
        swap(arr[i],arr[j]);
    }
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n; 
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }

    print(arr,n,0);
    return 0;
}