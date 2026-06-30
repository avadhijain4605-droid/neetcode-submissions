class Solution {
public:
    int help(int start,string& s, vector<string>& wordDict,vector<int>& dp){
        int n=s.size();
      //  if(start==n-1) return dp[start]=n-1;
        if(dp[start]!=-1) return dp[start];
        string w="";
        for(int i=start;i<n;i++){
            w+=s[i];
            if(find(wordDict.begin(),wordDict.end(),w)!=wordDict.end()){
                if(i==n-1) return dp[start]=1;
                else if(i<n-1&&help(i+1,s,wordDict,dp)) return dp[start]=1;
            }
        }
        return dp[start]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        return help(0,s,wordDict,dp);

    }
};
