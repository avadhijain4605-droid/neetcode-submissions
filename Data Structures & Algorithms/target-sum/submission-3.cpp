class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(auto i:nums)sum+=i;
        if((sum+target)%2==1||abs(target)>sum) return 0;
        int t=(sum+target)/2;
        vector<vector<int>>dp(n,vector<int>(t+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        if(t>=nums[0]) dp[0][nums[0]]=1;
        if(nums[0]==0) dp[0][0]=2;
        for(int i=1;i<n;i++){
            for(int k=0;k<=t;k++){
                dp[i][k]=dp[i-1][k]+(k>=nums[i]?dp[i-1][k-nums[i]]:0);
            }
        }
        return dp[n-1][t];
    }
};
