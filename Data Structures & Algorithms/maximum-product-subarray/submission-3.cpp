class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(2,vector<int>(n,0));
        dp[0][0]=nums[0];
        dp[1][0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>0){
                 dp[0][i]=min(nums[i]*dp[0][i-1],nums[i]);
                 dp[1][i]=max(nums[i]*dp[1][i-1],nums[i]);
            }
            else{
                 dp[1][i]=max(nums[i]*dp[0][i-1],nums[i]);
             dp[0][i]=min(nums[i]*dp[1][i-1],nums[i]);
            }
        }
        return *max_element(dp[1].begin(),dp[1].end());
    }
};
