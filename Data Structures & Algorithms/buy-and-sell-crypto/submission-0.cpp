class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>suffMax(n,0);
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--){
            suffMax[i]=maxi;
            maxi=max(maxi,prices[i]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,suffMax[i]-prices[i]);
        }
        return ans;
    }
};
