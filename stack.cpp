#include <bits/stdc++.h>
using namespace std;

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
};



int main()
{
    
    return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    return 0;
}