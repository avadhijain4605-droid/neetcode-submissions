class Solution {
public:
    int solve(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
        int n=prices.size();
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==0){
            dp[i][buy]=max(0+solve(i+1,buy,prices,dp),-prices[i]+solve(i+1,1,prices,dp));
        }
        else {
            dp[i][buy]=max(0+solve(i+1,buy,prices,dp),prices[i]+solve(i+2,0,prices,dp));
        }
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};
