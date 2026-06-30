class Solution {
public:
    int help(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        int n=nums.size();
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int pick=0;
        int np=help(i+1,prev,nums,dp);
        if(prev==-1||nums[i]>nums[prev]) pick=1+help(i+1,i,nums,dp);
        return dp[i][prev+1]=max(pick,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return help(0,-1,nums,dp);
    }
};
