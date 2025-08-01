#include <bits/stdc++.h>
using namespace std;



class Node{
    public:
    int x;
    int y;
    Node* next;
    Node(int x,int y){
        this->x=x;
        this->y=y;
        next=NULL;
    }
};

class Stack{
    Node* top=NULL;
    public:
    void push(int x,int y){
        Node* n=new Node(x,y);
        if (top==NULL){
            top=n;
        }
        else{
            n->next=top;
            top=n;
        }
    }

    Node* peek(){
        if (top!=NULL){
            return top;
        }
        else{
            return NULL;
        }
    }

    void pop(){
        if (top!=NULL){
            top=top->next;
        }
    }

    bool empty(){
        return top==NULL;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }

    int explored[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            explored[i][j]=0;
        }
    }

    Stack s;
    int i,j;
    s.push(0,0);
    while(!s.empty()){
        Node* temp=s.peek();
        i=temp->x;
        j=temp->y;
        if(i==n-1 && j==n-1){
            break;
        }
        explored[i][j]=1;
        s.pop();
        if (i+1<n && !explored[i+1][j] && arr[i+1][j]==1){
            s.push(i+1,j);
        }
        if (i-1>=0 && !explored[i-1][j] && arr[i-1][j]==1){
            s.push(i-1,j);
        }
        if (j+1<n && !explored[i][j+1] && arr[i][j+1]==1){
            s.push(i,j+1);
        }
        if (j-1>=0 && !explored[i][j-1] && arr[i][j-1]==1){
            s.push(i,j-1);
        }
    }
    if (i==n-1 && j==n-1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}