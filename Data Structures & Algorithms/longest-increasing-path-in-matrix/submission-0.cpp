class Solution {
public:
    vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int x,int y,vector<vector<int>>& dp,vector<vector<int>>& matrix){
        if(dp[x][y]!=-1) return dp[x][y];
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=1;
        for(int i=0;i<4;i++){
            int dx=x+dir[i][0];
            int dy=y+dir[i][1];
            if(dx>=0&&dx<n&&dy>=0&&dy<m&&matrix[dx][dy]>matrix[x][y]){
                ans=max(ans,1+dfs(dx,dy,dp,matrix));
            }
        }
        return dp[x][y]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1)dfs(i,j,dp,matrix);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
