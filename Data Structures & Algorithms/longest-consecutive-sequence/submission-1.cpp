class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mpp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(mpp.find(num-1)!=mpp.end()){
                mpp[num]=mpp[num-1]+1;
            }
            else mpp[num]=1;
            maxi=max(maxi,mpp[num]);
        }
        return maxi==INT_MIN?0:maxi;
    }
};
