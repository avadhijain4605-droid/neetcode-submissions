class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0;
        int r=h.size()-1;
        int maxi=INT_MIN;
        while(l<r){
            int area=(r-l)*min(h[r],h[l]);
            maxi=max(area,maxi);
            if(h[l]<h[r])l++;
            else r--;
        }
        return maxi;
    }
};
