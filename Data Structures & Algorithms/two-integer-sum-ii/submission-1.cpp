class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        vector<int>ans(2,-1);
        while(l<r){
            if(nums[l]+nums[r]==target){
                ans[0]=l+1;
                ans[1]=r+1;
                return ans;
            }
            else if(nums[l]+nums[r]>target)r--;
            else l++;
        }
        return ans;
    }
};
