#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    char x;
    Node* next=NULL;
    Node(char d){
        x=d;
        next=NULL;
    }
};

class Stack{
    Node* top=NULL;
    public:
    void push(char x){
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
}
;



void generate(Stack s,int open,int close,int n){
    if (open==n && close==n){
        s.display();
        cout<<endl;
        return;
    }
    if (open<n){
        s.push('(');
        generate(s,open+1,close,n);
        s.pop();
    }
    if (close<open){
        s.push(')');
        generate(s,open,close+1,n);
        s.pop();
    }

}




int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Stack s;
    int n;  
    cin>>n;
    generate(s,0,0,n);
    return 0;
}