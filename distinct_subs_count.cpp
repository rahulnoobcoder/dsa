
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    map<char,node*> links;
    bool flag;
    node(){
        flag = false;
    }
};


class trie{
    node* root;
    public:
    trie(){
        root = new node();
    }
    int insert(string s,int k){
        node* temp = root;
        int count=0;
        for(int i=k ;i<s.size();i++){
            auto mp = temp->links;
            if (mp.find(s[i]-'a')==mp.end()){
                temp->links[s[i]-'a'] = new node();
                count++;
            }
            temp = temp->links[s[i]-'a'];
        }
        temp->flag = true;
        return count;
    }

};



int countDistinctSubstring(string s) {
    int sum = 0;
    trie t;
    int n = s.size();
    for(int i=0;i<n;i++){
        sum += t.insert(s, i);
    }
    return sum+1;
}