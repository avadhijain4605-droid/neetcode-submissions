class Solution {
public:
    int solve(int start,int end,vector<int>& nums){
        int n=end-start+1;
        if(n==1) return nums[start];
        else if(n==2) return max(nums[start],nums[end]);
        vector<int>dp(n,0);
        dp[0]=nums[start];
        dp[1]=max(nums[start+1],nums[start]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+nums[i+start],dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int ans=max(solve(0,n-2,nums),solve(1,n-1,nums));
        return ans;
    }
};
