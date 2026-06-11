class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto i:nums){
            if(mpp[i]>=1) return i;
            mpp[i]++;
        }
        return -1;
    }
};
