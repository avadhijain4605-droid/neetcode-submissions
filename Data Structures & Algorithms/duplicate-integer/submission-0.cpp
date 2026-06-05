class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i:nums){
            if(mpp.count(i)) return true;
            mpp[i]++;
        }
        return false;
    }
};