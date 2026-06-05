class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int start=0;
        int end=0;
        unordered_map<char,int>mpp;
        while(end<s.size()){
            mpp[s[end]]++;
            while(start<end&&mpp[s[end]]>1){
                mpp[s[start]]--;
                if(mpp[s[start]]==0)mpp.erase(s[start]);
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};
