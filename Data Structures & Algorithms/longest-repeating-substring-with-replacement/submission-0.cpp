class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        vector<int>freq(26,0);
        int start=0;
        int end=0;
        int n=s.size();
        int maxf=0;
        while(end<n){
            freq[s[end]-'A']++;
            maxf=max(maxf,freq[s[end]-'A']);
            while(start<end&&end-start+1-maxf>k){
                freq[s[start]-'A']--;
                maxf=max(maxf,freq[s[start]-'A']);
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};
