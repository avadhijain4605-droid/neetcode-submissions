class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int ind,int sum,vector<int>&path,vector<int>&nums,int target){
        int n=nums.size();
        if(sum==target){
            ans.push_back(path);
            return;
        }
        else if(sum>target||ind>=n) return;
        path.push_back(nums[ind]);
        dfs(ind,sum+nums[ind],path,nums,target);
        path.pop_back();
        dfs(ind+1,sum,path,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>path;
        dfs(0,0,path,nums,target);
        return ans;
    }
};
