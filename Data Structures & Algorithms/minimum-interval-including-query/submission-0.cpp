class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& in, vector<int>& queries) {
        int maxi=INT_MIN;
        for(auto it:in)maxi=max(maxi,it[1]);
        vector<int>pre(maxi+1,1e9);
        for(auto it:in){
            int s=it[0];
            int e=it[1];
            int len=e-s+1;
            for(int i=s;i<=e;i++)pre[i]=min(pre[i],len);
        }
        vector<int>ans;
        for(int q:queries){
            if(q>maxi||pre[q]==1e9)ans.push_back(-1);
            else ans.push_back(pre[q]);
        }
        return ans;
    }
};
