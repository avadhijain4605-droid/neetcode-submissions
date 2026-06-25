class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=true;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx=x+dir[i][0];
                int dy=y+dir[i][1];
                if(dx>=0&&dx<n&&dy>=0&&dy<m&&grid[dx][dy]=='1'&&!vis[dx][dy]){
                    vis[dx][dy]=true;
                    q.push({dx,dy});
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&& !vis[i][j]){
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
