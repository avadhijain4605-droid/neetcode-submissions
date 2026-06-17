class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto p:points){
            int x=p[0];
            int y=p[1];
            double dist=sqrt(x*x+y*y);
            pq.push({dist,{x,y}});
        }
        int n=pq.size()-k;
        while(n--){
            pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            ans.push_back(vector<int>{x,y});
        }
        return ans;
    }
};
