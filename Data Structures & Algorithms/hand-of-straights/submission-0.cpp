class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n=hand.size();
        if(n%gs!=0) return false;
        int b=n/gs;
        vector<pair<int,int>>v(b,{0,-1});
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            int val=hand[i];
            bool flag=false;
            for(int j=0;j<b;j++){
                if(v[j].first==gs) continue;
                if(v[j].first==0||v[j].second==val-1){
                    v[j].first++;
                    v[j].second=val;
                    flag=true;
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
};
