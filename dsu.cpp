#include <bits/stdc++.h>
using namespace std;



class disjoint_set{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    disjoint_set(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0;i<n;i++) parent[i]=i;
    }
    int find_par(int n){
        if (n==parent[n]) return n;

        return parent[n] = find_par(parent[n]);

    }

    void set_union(int u,int v){

        int pu = find_par(u);
        int pv = find_par(v);
        if (pu==pv) return;
        if (rank[pu] > rank [pv]){
            parent[pv]=pu;
        }
        else if (rank [pv] > rank [pu]){
            parent[pu]=pv;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
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
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    return 0;
}