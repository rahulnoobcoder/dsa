class Solution {
public:


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
                    temp = temp->links[1-dig];
                }
                else temp = temp->links[dig];
                k--;
            }
            return num;
        }
    };
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& arr) {
        sort(nums.begin(),nums.end());
        vector<tuple<int,int,int>> temp; // (second value, first value, old_index)
        for (int i = 0; i < arr.size(); i++) {
            temp.push_back({arr[i][1], arr[i][0], i}); 
        }
        sort(temp.begin(), temp.end());
        trie t;
        vector<int> ans(arr.size());
        int i=0;
        int n = nums.size();
        for(auto [m,x,id]:temp){
            // int x = j[1],m=j[0],id=j[2];
            while(i<n && nums[i]<=m){
                t.insert(nums[i]);
                i++;
            }
            if (m < nums[0]){
                ans[id]=-1;
            }
            else{
                ans[id]=t.max_xor(x);
            }
        }
        return ans;
    }
};