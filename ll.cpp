#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int x){
        data=x;
        next=NULL;
    }

};


class ll{
    public:
    Node* head=NULL;

    void insert(int data){
        if (head==NULL){
            head = new Node(data);
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new Node(data);
        }
    }

    Node* get_head(){
        return head;
    }

    Node* get_mid(Node* ptr){
        Node* slow=ptr,*fast=ptr;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    void display(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void merge_sort(Node* left){
        if (left!=NULL){
            Node* mid=get_mid(left);
            Node* right=mid->next;
            mid->next=NULL;
            display(left);
            display(right);
            // merge_sort(left);
            // merge_sort(right);


            // merge(left,right);
        }
    }



    
};

int main()

{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif    
    int n;

    ll l1;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;  
        l1.insert(x); 
    }

    Node* ptr=l1.get_mid(l1.head);

    l1.merge_sort(l1.head);
    return 0;
}