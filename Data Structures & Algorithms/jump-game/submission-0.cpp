class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
       // vector<int>dp(n,0);
       int goal=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=goal){
                goal=i;
            }
        }
        return goal==0;
    }
};
