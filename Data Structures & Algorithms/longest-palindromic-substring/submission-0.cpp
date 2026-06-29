class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start;
        int len=0;
        for(int i=0;i<n;i++){
            //odd length
            int l=i;
            int r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
                if(len<r-l+1){
                cout<<i<<endl;
                start=l;
                len=r-l+1;
            }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                if(len<r-l+1){
                start=l;
                len=r-l+1;
            }
                l--;
                r++;
            }
        }
        if(start==-1) return "";
        return s.substr(start,len);
    }
};
