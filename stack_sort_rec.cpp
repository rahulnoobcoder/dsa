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

    int peek(){
        if (top!=NULL){
            return top->data;
        }
        else{
            return -1;
        }
    }

    int pop(){
        if (top!=NULL){
            int x = top->data;
            top=top->next;
            return x;
        }
        else{
            return -1;
        }
    }

    bool empty(){
        return top==NULL;
    }

    void display(){
        Node* temp=top;

        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};


void sort(Stack &s,Stack &s1){ // single stack space
    if(s.empty()){
        return;
    }

    int x= s.pop();
    while(!s1.empty() && s1.peek()<x){
            s.push(s1.pop());
    }
    s1.push(x);
    sort(s,s1);
}



// void sort(Stack &s,Stack &s1,Stack &s2){    2 stack space 
//     if(s.empty()){
//         return;
//     }

//     int x= s.pop();
//     while(!s1.empty() && s1.peek()>x){
//             s2.push(s1.pop());
//     }
//     s1.push(x);

//     while(!s2.empty()){
//         s1.push(s2.pop());
//     }

//     sort(s,s1,s2)
// }


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    
    Stack s;
    int x;
    for(int i = 0; i < n; ++i) {
        cin>>x;
        s.push(x);
    }


    Stack s1,s2;
    sort(s,s1);
    s1.display();
    // while(!s.empty()){
    //     int x= s.pop();


    //     while(!s1.empty() && s1.peek()>x){
    //         s2.push(s1.pop());
    //     }
    //     s1.push(x);

    //     while(!s2.empty()){
    //         s1.push(s2.pop());
    //     }
    // }
    // s1.display();

    return 0;
}