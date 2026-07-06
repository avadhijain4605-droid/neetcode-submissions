class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dp, string& text1, string& text2){
        //if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(text1[i]==text2[j]){
            ans=max(ans,1+solve(i-1,j-1,dp,text1,text2));
        }
        else{
        ans=max(solve(i-1,j,dp,text1,text2),solve(i,j-1,dp,text1,text2));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
       int n=text1.length();
       int m=text2.length();
       vector<vector<int>>dp(n,vector<int>(m,-1)); 
       return solve(n-1,m-1,dp,text1,text2);
    }
};
