class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        dis[0][0]=grid[0][0];
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int cost=pq.top().first;
            pq.pop();
            for(int i=0;i<4;i++){
                int dx=x+dir[i][0];
                int dy=y+dir[i][1];
                if(dx>=0&&dx<n&&dy>=0&&dy<n&&dis[dx][dy]>max(cost,grid[dx][dy])){
                    pq.push({max(cost,grid[dx][dy]),{dx,dy}});
                    dis[dx][dy]=max(cost,grid[dx][dy]);
                }
            }
        }
        return dis[n-1][n-1];
        
    }
};
