#include <bits/stdc++.h>
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


class ll{
    Node* head=NULL;
    public:
    void insert(int x){
        Node* n=new Node(x);
        if (head==NULL){
            head=n;
        }
        else{
            Node* temp=head;

            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=n;
        }
    }

    Node* get_head(){
        return head;
    }

    void reverse(Node* ptr){
        Node * temp=NULL,*curr=ptr,*prev=NULL;
        Node* t1=ptr;
        Node* mid=get_mid();
        while(curr!=mid){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        t1->next=temp;
        cout<<"mid : "<<mid->data<<endl;
        this->head=prev;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }


    Node* get_mid(){
        Node* slow=head,*fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    int check(){
        Node* slow=head,*fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        reverse(head);
        fast==NULL?slow=slow:slow=slow->next;
        Node* temp=head;
        while(slow!=NULL){
            if (temp->data!=slow->data){
                return 0;
            }
            temp=temp->next;
            slow=slow->next;
        }
        return 1;
    }
};


int main()
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll l1;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        l1.insert(x);
    }
    l1.check()?cout<<"YES\n":cout<<"No\n";  
}