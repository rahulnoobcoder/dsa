#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};


void insert(Node* &head,int x){
    if (head==NULL){
        head=new Node(x);
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new Node(x);
    }
}

void display(Node* head){
    if (head==NULL)
    return;

    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* get_mid(Node* head){
    Node* slow=head,*fast=head;
    Node* prev=NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return prev;
}


Node* merge(Node* left,Node* right){

    Node* dummy=new Node(-1);
    Node* temp=dummy;

    while(left!=NULL && right!=NULL){
        if (left->data < right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }

    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }

    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    return dummy->next;
}


Node* mergesort(Node* head){
    if (head==NULL || head->next==NULL){
        return head;
    }

    Node* mid=get_mid(head);

    Node* right=mid->next;
    mid->next=NULL;
    
    head=mergesort(head);
    right=mergesort(right);

    return merge(head,right);
}

int main()
{
    int n;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin>>n;

    Node* head=NULL;

    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        insert(head,x);
    }
    

    head=mergesort(head);

    display(head);

    return 0;
}