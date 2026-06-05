class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);
        int maxi=h[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi,h[i]);
             leftMax[i]=maxi;
        }
        maxi=h[n-1];
        for(int i=n-2;i>=0;i--){
            maxi=max(maxi,h[i]);
            rightMax[i]=maxi;
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            ans+=min(leftMax[i],rightMax[i])-h[i];
        }
        return ans;
    }
};
