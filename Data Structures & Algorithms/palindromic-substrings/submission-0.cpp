class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
       vector<int>dp(n,0); 
       for(int i=0;i<n;i++){
        int l=i;
        int r=i;
        while(l>=0&&r<n&&s[l]==s[r]){
            dp[i]++;
            l--;
            r++;
        }
        l=i;
        r=i+1;
        while(l>=0&&r<n&&s[l]==s[r]){
            dp[i]++;
            l--;
            r++;
        }
       }
       int sum=0;
       for(auto it:dp)sum+=it;
       return sum;
    }
};
