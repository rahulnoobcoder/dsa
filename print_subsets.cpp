#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int x;
    Node* next=NULL;
    Node(int d){
        x=d;
        next=NULL;
    }
};

class Stack{
    Node* top=NULL;
    public:
    void push(int x){
        Node* n=new Node(x);
        if (top==NULL){
            top=n;
        }
        else{
            n->next=top;
            top=n;
        }
    }


    Node* pop(){
        if (top!=NULL){
            Node* x  = top;
            top=top->next;
            return x;
        }
        return NULL;
    }
    void display(){
        if (top==NULL){
            return;
        }
        Node* x=pop();
        display();
        cout<<x->x;
        push(x->x);
    }
};


void print_subsets(int arr[],Stack &s,int n,int i){
    if (i==n){
        s.display();
        cout<<endl;
        return;
    }

    print_subsets(arr,s,n,i+1);
    s.push(arr[i]);
    print_subsets(arr,s,n,i+1);
    s.pop();
}


// void print_bin(int arr[],int dmm[],int i,int n){
//     if (i==1){
//         for(int j=0;j<i;j++){
//             if (dmm[j]!=0)
//             cout<<arr[j];
//         }
//         cout<<endl;
//         return;
//     }

//     dmm[i]=0;
//     print_bin(arr,dmm,i+1,n);
//     dmm[i]=1;
//     print_bin(arr,dmm,i+1,n);
// }

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
    Stack s;
    
    print_subsets(arr,s,n,0);
    // int dmm[n];
    // print_bin(arr,dmm,0,n);


    return 0;
}