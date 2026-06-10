class Solution {
public:
    int eatingTime(int rate,vector<int>& piles){
        int t=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            t+=ceil(1.0*piles[i]/rate);
        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            int curr=eatingTime(mid,piles);
           // cout<<mid<<" "<<curr<<endl;
            if(curr>h)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};
