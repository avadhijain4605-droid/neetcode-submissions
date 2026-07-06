class Solution {
public:
    int jump(vector<int>& nums) {
       int n=nums.size();
       int currEnd=0;
       int farthest=0;
       int step=0;
       for(int i=0;i<n-1;i++){
        farthest=max(farthest,nums[i]+i);
        if(i==currEnd){
            step++;
            currEnd=farthest;
        }
       } 
       return step;
    }
};
