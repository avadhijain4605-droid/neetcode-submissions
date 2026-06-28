class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        k++;
        vector<vector<int>>dist(n,vector<int>(k+1,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({0,{-k,src}});
        dist[src][k]=0;
        while(!pq.empty()){
            int node=pq.top().second.second;
            int num=-pq.top().second.first;
            int price=pq.top().first;
            pq.pop();
            if(node==dst) return price;
            if(dist[node][num]<price) continue;
            if(num==0)continue;
            num--;
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dist[v][num]>wt+price){
                    pq.push({wt+price,{-(num),v}});
                    dist[v][num]=wt+price;
                }
            }
        }
        return -1;
    }
};
