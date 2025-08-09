class Solution {
public:
    void solve(vector<int> &arr,int i,int n,int tot_sum,int cost,set<int> &ans,int count){
        if (count==n/2){
            ans.insert(abs(2*cost-tot_sum));
            return;
        }
        if (i==n){
            return;
        }
        solve(arr,i+1,n,tot_sum,cost+arr[i],ans,count+1);
        solve(arr,i+1,n,tot_sum,cost,ans,count);
    }    
    int minimumDifference(vector<int>& nums) {
        
        int tot_sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            tot_sum+=nums[i];
        }
        sort(nums.begin(),nums.end());
        set<int> ans;
        solve(nums,0,n,tot_sum,0,ans,0);
        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<endl;
        int min_val = *ans.begin();
        return min_val;
    }
};