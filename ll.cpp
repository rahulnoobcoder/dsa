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

    void display(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
};



int main()

{
    #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif    
    ll l1;
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);

    l1.display();
    return 0;
}