class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        //unordered_set<vector<int>>st;
        //st.push({});
        ans.push_back({});
        for(int i=0;i<n;i++){
            vector<vector<int>>temp;
            for(const auto &it:ans){
                vector<int>curr=it;
                curr.push_back(nums[i]);
                temp.push_back(curr);
            }
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        return ans;
    }
};
