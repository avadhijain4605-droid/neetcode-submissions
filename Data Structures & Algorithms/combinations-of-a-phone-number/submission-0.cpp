class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>>mpp;
        int s=0;
        for(int i=2;i<=9;i++){
            for(int j=0;j<3;j++){
                 mpp[i].push_back('a'+s);
                 s++;
            }
            if(i==7||i==9){
                mpp[i].push_back('a'+s);
                s++;
            }
        }
        unordered_set<string>st;
        st.insert("");
        int n=digits.size();
        if(n==0) return {};
        for(int i=0;i<n;i++){
            char c=digits[i];
            unordered_set<string>nxt;
            for(auto& it:st){
                for(char s:mpp[c-'0']){
                    nxt.insert(it+s);
                }
            }
            st=move(nxt);
        }
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};