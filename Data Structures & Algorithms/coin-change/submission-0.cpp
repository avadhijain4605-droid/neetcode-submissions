class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        for(int i=0;i<n;i++)dp[i][0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=amount;j++){
                if(i>0)dp[i][j]=dp[i-1][j];
                if(j<coins[i])continue;
                dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i]]);
            }
        }
        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];
    }
};
