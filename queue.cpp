class Node{
    public:
    char data;
    Node* next;

    Node(char x){
        data=x;
        next=NULL;
    }
};

class Queue{
    Node *front=NULL,*rear=NULL;
    int count=0;
    public:
    bool empty(){
        return front==NULL;
    }

    void enqueue(char k){    
        Node *n = new Node(k);
        if (front==NULL){
            front=rear=n;
        }
        else{
            rear->next=n;
            rear=n;
        }
        count++;
    }

    void dequeue(){
        if (front!=NULL){
            Node* temp = front;
            front = front->next;
            delete temp;
            count--;
        }
        else{
            cout<<"queue is empty"<<endl;
        }
    }
    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    char peek(){
        if (front!=NULL)
        return front->data;
        else{
            return -1;
        }
    }

    int length(){
        return count;
    }
};


#include<iostream>
using namespace std;

int main()
{
    
    return 0;
}