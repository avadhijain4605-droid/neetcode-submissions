class Solution {
public:
    set<vector<int>>st;
    void dfs(int ind,vector<int>&nums,vector<int> curr){
        int n=nums.size();
        if(ind==n){
            sort(curr.begin(),curr.end());
            if(st.find(curr)==st.end()) st.insert(curr);
            return;
        }
        curr.push_back(nums[ind]);
        dfs(ind+1,nums,curr);
        curr.pop_back();
        dfs(ind+1,nums,curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //vector<vector<int>>ans;
        dfs(0,nums,{});
       vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
