class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(int x, int y,
             vector<vector<int>>& h,
             vector<vector<bool>>& vis) {

        int n = h.size();
        int m = h[0].size();

        vis[x][y] = true;

        for(auto &d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if(vis[nx][ny])
                continue;

            if(h[nx][ny] < h[x][y])
                continue;

            dfs(nx, ny, h, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m,false));
        vector<vector<bool>> atlantic(n, vector<bool>(m,false));

        for(int i=0;i<n;i++) {
            dfs(i,0,h,pacific);
            dfs(i,m-1,h,atlantic);
        }

        for(int j=0;j<m;j++) {
            dfs(0,j,h,pacific);
            dfs(n-1,j,h,atlantic);
        }

        vector<vector<int>> ans;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};