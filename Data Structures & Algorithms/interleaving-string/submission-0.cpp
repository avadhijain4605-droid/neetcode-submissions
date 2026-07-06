#include <cstring>
class Solution {
public:
    int dp[101][101];
    string s,t,a;
    int solve(int i,int j){
        int n=s.size();
        int m=t.size();
        if(i>=n&&j>=m) return true;
       // if(k<0) return false;
        if(i<n&&j<m&&dp[i][j]!=-1) return dp[i][j];
        int k=i+j;
        if(i>=0&&j>=0&&s[i]==a[k]&&t[j]==a[k])return dp[i][j]=solve(i+1,j)|solve(i,j+1);
        else if(i<n&&s[i]==a[k]) return dp[i][j]=solve(i+1,j);
        else if(j<m&&t[j]==a[k])return dp[i][j]=solve(i,j+1);
        else return dp[i][j]=0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        s=s1;
        t=s2;
        a=s3;
        memset(dp,-1,sizeof(dp));
        if(s.size()+t.size()!=a.size()) return false;
        return solve(0,0);
    }
};
