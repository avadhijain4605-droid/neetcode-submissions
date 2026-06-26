class Solution {
   public:
   void dfs(int x,int y, vector<vector<char>>& board){
    int n=board.size();
    int m=board[0].size();
    if(x>=n||y>=m||x<0||y<0||board[x][y]=='X'||board[x][y]=='T') return;
    board[x][y]='T';
    dfs(x+1,y,board);
    dfs(x-1,y,board);
    dfs(x,y+1,board);
    dfs(x,y-1,board);
   }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
            }
            if (board[i][m-1]=='O'){
                dfs(i,m-1,board);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(0,i,board);
            }
            if(board[n-1][i]=='O'){
                dfs(n-1,i,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='T') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
