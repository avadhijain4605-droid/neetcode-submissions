class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>st;
        vector<pair<int,double>>pos;
        int n=position.size();
        for(int i=0;i<n;i++){
            double t=((double)target-position[i])/(double)speed[i];
            pos.push_back({position[i],t});
        }
        sort(pos.begin(),pos.end(),[&](auto& a,auto& b){
            return a.first>b.first||(a.first==b.first&&a.second<b.second);
        });
        for(int i=0;i<n;i++){
            if(!st.empty()&&st.top()==pos[i].second)continue;
            else if(st.empty()) st.push(pos[i].second);
            else{
                if(pos[i].second>st.top()) st.push(pos[i].second);
            }
        }
        return st.size();
    }
};
