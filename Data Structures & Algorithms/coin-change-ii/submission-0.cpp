class Solution {
public:
    int solve(int i,int amt,vector<int>& coins,vector<vector<int>>& dp){
        int n=coins.size();
        if(amt==0) return 1;
        if(i>=n) return amt==0;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int np=solve(i+1,amt,coins,dp);
        int p=0;
        if(amt>=coins[i]){
            p=solve(i,amt-coins[i],coins,dp);
        }
        return dp[i][amt]=p+np;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};
