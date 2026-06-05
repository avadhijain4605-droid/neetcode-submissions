class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int>vis(9,0);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(vis[board[i][j]-'1']==0)
                vis[board[i][j]-'1']=1;
                else return false;
            }
        }
        for(int j=0;j<9;j++){
            vector<int>vis(9,0);
            for(int i=0;i<9;i++){
                if(board[i][j]=='.')continue;
                if(vis[board[i][j]-'1']==0)
                vis[board[i][j]-'1']=1;
                else return false;
            }
        }
        for(int boxRow=0;boxRow<9;boxRow+=3){
            for(int boxCol=0;boxCol<9;boxCol+=3){
                vector<int>vis(9,0);
                for(int i=boxRow;i<boxRow+3;i++){
                    for(int j=boxCol;j<boxCol+3;j++){
                        if(board[i][j]=='.')continue;
                        if(vis[board[i][j]-'1']==0)
                        vis[board[i][j]-'1']=1;
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};
