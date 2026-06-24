class Solution {
public:
    vector<vector<string>>ans;
    bool isValid(int row,int col,vector<vector<bool>>& vis){
        int n=vis.size();
        for(int i=0;i<n;i++){
            if(i==row) continue;
            if(vis[i][col]) return false;
        }
        for(int i=0;i<n;i++){
            if(i==col) continue;
            if(vis[row][i]) return false;
        }
        for(int i=0;i<n;i++){
            if(row+i<n&&col+i<n && vis[row+i][col+i]) return false;
            else if(row-i>=0&&col-i>=0&& vis[row-i][col-i]) return false;
            else if(row+i<n&& col-i>=0 && vis[row+i][col-i]) return false;
            else if(row-i>=0&& col+i<n&& vis[row-i][col+i]) return false;
        }
        return true;
    }
    void dfs(int row,int n,vector<vector<bool>>& vis, vector<int>&curr){
        if(row==n){
            vector<string>temp;
            for(int i=0;i<n;i++){
                string a;
                for(int j=0;j<n;j++){
                    if(j==curr[i]) a+='Q';
                    else a+='.';
                }
                temp.push_back(a);
            }
            ans.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(row,col,vis)){
                vis[row][col]=true;
                curr.push_back(col);
                dfs(row+1,n,vis,curr);
                curr.pop_back();
                vis[row][col]=false;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vector<int>curr={};
        dfs(0,n,vis,curr);
        return ans;
    }
};
