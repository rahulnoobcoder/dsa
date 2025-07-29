#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    long long x;
    int y;
    Node* next=NULL;
    Node(int x){
        this->x=1;
        y=0;
        next=NULL;
    }
};


class ll{
    Node* head=NULL;
    public:
    void insert(int x){
        Node* n = new Node(x);
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

    Node* search(int k){
        Node* temp=head;
        while(temp->next!=NULL){
            if (temp->x==k){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
};


long long solve(int n,Node* head){


    if (search)
}





int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int n;
    cin>>n;
    return 0;
}