class Solution {
public:
    int help(int ind,string& s,vector<int>& dp){
        int n=dp.size();
        if(ind==n) return 1;
        if(s[ind]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=help(ind+1,s,dp);
        if(ind+1<n){
            int num=(s[ind]-'0')*10+s[ind+1]-'0';
            if(num<=26){
                ans+=help(ind+2,s,dp);
            }
        }
        
        return dp[ind]=ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return help(0,s,dp);
    }
};
