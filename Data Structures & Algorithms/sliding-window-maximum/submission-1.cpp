class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxi=0;
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;
        int start=0;
        int end=0;
        while(end<n){
            while(!dq.empty()&&nums[dq.back()]<nums[end])dq.pop_back();
            dq.push_back(end);
            if(end-start+1==k){
                ans.push_back(nums[dq.front()]);
                if(end-dq.front()+1>=k) dq.pop_front();
                start++;
            }
            end++;
        }
        return ans;
    }
};
