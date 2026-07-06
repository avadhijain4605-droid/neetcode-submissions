class Solution {
public:
    int solve(int i,int j,string s,string p,vector<vector<int>>& dp){
        if(i<0&&j<0) return true;
        if(j<0) return false;
        if(i<0){
            if(j>=0&&p[j]=='*')return solve(i,j-2,s,p,dp);
            return false;
        }
        if(i>=0&&j>=0&&dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j]||p[j]=='.') return dp[i][j]=solve(i-1,j-1,s,p,dp);
        else if(p[j]=='*'){
            bool ans=solve(i,j-2,s,p,dp);
            if(p[j-1]==s[i]||p[j-1]=='.')
            ans|=solve(i-1,j,s,p,dp);
            return dp[i][j]=ans;
        } 
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        //if(n<m) return false;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,p,dp);
    }
};
