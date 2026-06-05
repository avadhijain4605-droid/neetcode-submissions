class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        int n=strs.size();
         for(int i=0;i<n;i++){
            string sz=to_string(strs[i].size());
            ans=ans+sz+"#"+strs[i];
        }
        for(int i=0;i<ans.size();i++)cout<<ans[i];
        return ans;
    }

    vector<string> decode(string s) {
        int i=0;
        int n=s.size();
        vector<string>ans;
        while(i<n){
            int len=0;
            while(i<n&&s[i]>='0'&&s[i]<='9'){
                len*=10;
                len+=s[i]-'0';
                i++;
            }
            i++;
            string subs=s.substr(i,len);
            ans.push_back(subs);
            i+=len;
        }
        return ans;
    }
};
