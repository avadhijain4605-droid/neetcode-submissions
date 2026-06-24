class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int ind,vector<int>& nums,vector<int>& curr,unordered_set<int>& vis){
        int n=nums.size();
        if(ind==n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis.find(nums[i])==vis.end()){
            vis.insert(nums[i]);
            curr.push_back(nums[i]);
            dfs(ind+1,nums,curr,vis);
            curr.pop_back();
            vis.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int>vis;
        vector<int>curr={};
        dfs(0,nums,curr,vis);
        return ans;
    }
};
