class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int dx=x+dir[j][0];
                    int dy=y+dir[j][1];
                    if(dx>=0&&dx<n&&dy>=0&&dy<m&&grid[dx][dy]==1){
                        grid[dx][dy]=2;
                        q.push({dx,dy});
                    }
                }
            }
            cnt++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return cnt==0?0:cnt-1;
    }
};
