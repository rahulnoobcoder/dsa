#include<iostream>
using namespace std;
int longest_palindrome_dp(int l,int r,int n,char* str,int** dp){
    if(l==r) return 1;
    if(l>r) return 0;
    // if(dp[l][r]!=-1) return dp[l][r];
    int take = 0;
    int not_take = 0;
    if(str[l]==str[r]){
        return(2 + longest_palindrome_dp(l+1,r-1,n,str,dp));
        // return take;
    }else{
        return max(longest_palindrome_dp(l+1,r,n,str,dp),longest_palindrome_dp(l,r-1,n,str,dp));
        // return not_take;

    }
    // dp[l][r] = max(take,not_take);
    // return max(take,not_take);
    // return max(take,not_take)
}
int main() {
    int n;
    cin >> n;
    char str[n+1];  
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    int** dp = new int*[n];
    for(int i = 0; i < n; i++) {
        dp[i] = new int[n];
        for(int j = 0; j < n; j++) {
            dp[i][j] = -1;
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // cleanup
    cout<<longest_palindrome_dp(0,n-1,n,str,dp);
    return 0;
}