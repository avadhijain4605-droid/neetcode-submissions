class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        vector<int>ans(2,-1);
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(mpp.find(rem)!=mpp.end()){
                ans[0]=mpp[rem];
                ans[1]=i;
                return ans;
            }
            mpp[nums[i]]=i;
        }
        return ans;
    }
};
