#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left,*right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

Node* insert(int x,Node* root){
    if (root==NULL) return new Node(x);

    if (root->data < x) root->right=insert(x,root->right);
    else root->left=insert(x,root->left);
}


Node* search(Node* root,int x){
    if (root==NULL) return NULL;

    if (root->data == x)
    return root;

    if (root->data > x){
        return search(root->left,x);
    }

    else{
        return search(root->right,x);
    }
}

void display(Node* root){
    if (root!=NULL){


        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}

int ceil_(Node* root,int key){
    int ceil=-1;
    while(root){
        if (root->data==key){
            ceil=key;
            return ceil;
        }
        else if (root->data > key){
            ceil=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ceil;
}

int floor(Node* root,int key){
    int fl=-1;
    while(root){
        if (root->data==key){
            fl=key;
            return fl;
        }
        else if (root->data < key){
            fl=root->data;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return fl;

}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    Node* root=NULL;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        root=insert(arr[i],root);
    }

    // display(root);
    int k=6;
    cout<<ceil_(root,10)<<endl;
    cout<<floor(root,48);
    
    return 0;
}