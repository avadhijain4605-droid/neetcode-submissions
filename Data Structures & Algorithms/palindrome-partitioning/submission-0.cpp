class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string& s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(int ind,string& s,vector<string>& curr){
        if(ind==s.length()){
            ans.push_back(curr);
            return;
        }
        int n=s.size();
        for(int i=ind;i<n;i++){
            if(isPalindrome(s,ind,i)){
                curr.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr={};
        solve(0,s,curr);
        return ans;
    }
};
