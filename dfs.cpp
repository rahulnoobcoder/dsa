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




void dfs(Node* graph[],int i,int visited[]){
    Node* temp = graph[i];
    cout<<i<<" ";
    visited[i]=1;
    while(temp!=NULL){
        if (!visited[temp->data]){
            dfs(graph,temp->data,visited);
        }
        temp=temp->next;
    }
}




int main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;

    Node* graph[n+1];
    for(int i = 0; i <= n; i++) {
    graph[i] = NULL;
    }
    int x, y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        insert(graph[x],y);
        insert(graph[y],x);
    }

    int visited[n+1];
    for(int i = 1; i <= n; i++) {
        visited[i]=0;
    }

    dfs(graph,4,visited);

    

    return 0;
}