class Solution {
public:
    vector<string> ans;
    void dfs(int ind,string& curr,int sum,int n){
        if(sum==0&&ind==n){
            ans.push_back(curr);
            return;
        }
        else if(sum<0||ind>n) return;
        curr+='(';
        dfs(ind+1,curr,sum+1,n);
        curr.erase(prev(curr.end()));
        curr+=')';
        dfs(ind+1,curr,sum-1,n);
        curr.erase((prev(curr.end())));
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        dfs(0,curr,0,2*n);
        return ans;
    }
};
