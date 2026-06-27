class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>>adj(n);
       k--;
       for(auto it:times){
        int u=it[0];
        int v=it[1];
        int w=it[2];
        u--;
        v--;
        adj[u].push_back({v,w});
        //adj[v].push_back({u,w});
       } 
       vector<int>dis(n,1e9);
       dis[k]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
       pq.push({0,k});
       while(!pq.empty()){
        int node=pq.top().second;
        int time=pq.top().first;
        pq.pop();
        for(const auto&[v,wt]:adj[node]){
            if(dis[v]>time+wt){
                pq.push({time+wt,v});
                dis[v]=time+wt;
            }
        }
       }
       int ans=0;
       for(auto i:dis)ans=max(ans,i);
       return ans==1e9?-1:ans;
    }
};
