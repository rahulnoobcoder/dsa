#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int n;
    int sum;
    int val;
    Node* next;
    Node(int x,int y,int v){
        n=x;
        sum=y;
        val=v;
        next=NULL;
    }
};

class ll{
    Node* head=NULL;
    public:
    void insert(int n,int sum,int val){
        Node* nm= new Node(n,sum,val);
        if (head==NULL){
            head=nm;
            return;
        }        
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nm;
    }


    int search(int n,int sum){
        Node* temp=head;
        while(temp!=NULL){
            if (temp->n==n && temp->sum==sum){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }
};





int sub_seq(int arr[],int i,int n,int sum,ll &l){
    if (i==n){
        if (sum==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int k=l.search(i,sum);
    if (k!=-1){
        return k;
    }

    int take=sub_seq(arr,i+1,n,sum-arr[i],l);
    int ntake=sub_seq(arr,i+1,n,sum,l);
    int total=take+ntake;
    l.insert(i,sum,total);
    return total;
}





int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin >> n>>m;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll list;

    cout<<sub_seq(arr,0,n,m,list);

    return 0;
}