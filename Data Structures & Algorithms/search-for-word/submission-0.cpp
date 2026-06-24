class Solution {
public:
    bool dfs(int i,int j,int ind,vector<vector<char>>& board,string& word,vector<vector<bool>>& vis){
        if(ind==word.size()-1){
        if(board[i][j]==word[ind]) return true;
        else return false;
        }
        int n=board.size();
        int m=board[0].size();
       vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
       bool ans=false;
       for(int k=0;k<4;k++){
        int dx=i+dir[k][0];
        int dy=j+dir[k][1];
        if(dx>=0&&dx<n&&dy>=0&&dy<m&&!vis[dx][dy]&&board[dx][dy]==word[ind+1]){
            vis[dx][dy]=true;
            ans|=dfs(dx,dy,ind+1,board,word,vis);
            vis[dx][dy]=false;
        }
       }
       return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    bool ans=dfs(i,j,0,board,word,vis);
                    vis[i][j]=false;
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};
