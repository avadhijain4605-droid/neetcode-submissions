class Solution {
public:
    bool help(int i,int sum,vector<int>& nums,vector<vector<int>>& dp){
        int n=nums.size();
        if(i==n) return sum==0;
        if(sum<0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int np=help(i+1,sum,nums,dp);
        int p=0;
        if(sum>=nums[i])p=help(i+1,sum-nums[i],nums,dp);
        return dp[i][sum]=p||np;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)total+=nums[i];
        if((total%2)==1) return false;
        int sum=total/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return help(0,sum,nums,dp);
    }
};
