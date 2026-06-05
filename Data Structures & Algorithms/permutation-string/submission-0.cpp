class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.size();
        vector<int>freq(26,0);
        for(char c:s1)freq[c-'a']++;
        int start=0;
        int end=0;
        while(end<m){
            freq[s2[end]-'a']--;
            while(end-start+1>n){
                freq[s2[start]-'a']++;
                start++;
            }
            if(all_of(freq.begin(),freq.end(),[](int x){return x==0;})) return true;
            end++;
        }
        return false;
    }
};
