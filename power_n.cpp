#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int power;
    double val;
    Node* next;

    Node(int p,double v){
        power=p;
        val=v;
        next=NULL;
    }
};

void insert(int n,double val,Node* &head){
    if (head==NULL){
        head=new Node(n,val);
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new Node(n,val);
    }
}

Node* search(int k,Node* head){
    Node* temp=head;

    while(temp!=NULL){
        if (k==temp->power){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
double calc(int x,int n,Node* &head){
    if (n<2){
        return x*n;
    }
    Node* k=search(n,head);
    if (k!=NULL){
        return k->val;
    }
    double half = calc(x, n/2, head);
    double pow = (n % 2 == 0) ? half * half : half * half * x;
    insert(n,pow,head);

    return search(n,head)->val;

}
        
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,x;
    cin>>x>>n;
    Node* head=NULL;

    cout<<calc(x,n,head);
    return 0;
}