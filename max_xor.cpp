    #include <bits/stdc++.h>
    using namespace std;

    class node{
        public:
        bool flag;
        node* links[2];
        node(){
            flag=false;
            links[0]=links[1]=NULL;
        }
    };

    class trie{
        node* root;
        public:
        trie(){
            root = new node();
        }

        void insert(int n){
            node* temp = root;
            int k = 31;
            while(k>=0){
                int dig = (n>>k) & 1;
                if (temp->links[dig]==NULL){
                    temp->links[dig] = new node();
                }
                temp = temp->links[dig];
                k--;
            }
            temp->flag = true;
        }


        int max_xor(int n){
            node* temp = root;

            int num = 0 ;   
            int k = 31;
            while(k>=0){
                int dig = (n>>k) & 1;
                if (temp->links[1-dig]!=NULL){
                    num  = num + (1<<(k));
                    cout<<k<<endl;
                    temp = temp->links[1-dig];
                }
                else temp = temp->links[dig];
                k--;
            }
            return num;
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
        vector<int> v(n);
        trie t;
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
            t.insert(v[i]);
        }


        cout<<t.max_xor(8);
        
        

        return 0;
    }