class Solution {
public:
    bool isPalindrome(string s) {
        string a="";
        for(char c:s){
           if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            a+=tolower(c);
            else if(c>='0'&&c<='9')a+=c;
        }
        //for(int i=0;i<a.size();i++)cout<<a[i];
        int l=0;
        int r=a.size()-1;
        while(l<=r){
            if(a[l]!=a[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
