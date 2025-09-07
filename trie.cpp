#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    node* links[26] ;
    bool flag=false;
    node(){
        for(int i=0;i < 26;i++) links[i]=NULL;
    }
    bool contains(char x){
        return links[x-'a']!=NULL;
    }

    void put(char ch,node* x){
        links[ch-'a']=x;
    }

    node* get(char ch){
        return links[ch-'a'];
    }

    void set_end(){
        flag=true;
    }

    bool get_flag(){
        return flag;
    }
};

class trie{
    node* root;
    public:
    trie(){
        root=new node();
    }

    void insert(string word){
        node* nod=root;
        for(int i=0;i<word.size();i++){
            if (!nod->contains(word[i])){
                nod->put(word[i],new node() );
            }
            nod = nod->get(word[i]);
        }
        nod->set_end();
    }


    bool search(string word){
        node* node=root;
        for(int i=0;i<word.size();i++){
            if (!node->contains(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->get_flag();
    }

    bool contains_word(string word){
        node* curr=root;
        for(int i=0;i<word.size();i++){
            if (!curr->contains(word[i])){
                return false;
            }
            curr = curr->get(word[i]);
        }
        return true;
    }

};

int main()
{
   
    trie t;

    t.insert("hello");
    t.insert("meow");
    t.insert("hell");

    cout<<t.search("hell")<<endl;
    cout<<t.contains_word("hel");
    
    
    return 0;
}