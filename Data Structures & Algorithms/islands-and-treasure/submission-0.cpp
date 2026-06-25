class Solution {
public:
    const int INF=INT_MAX;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)q.push({i,j});
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx=x+dir[i][0];
                int dy=y+dir[i][1];
                if(dx>=0&&dx<n&&dy>=0&&dy<m&&grid[dx][dy]==INF){
                   grid[dx][dy]=grid[x][y]+1;
                   q.push({dx,dy}); 
                }
            }
        }
    }
};
