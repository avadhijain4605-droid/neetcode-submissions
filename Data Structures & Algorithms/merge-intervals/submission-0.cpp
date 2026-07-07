class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>>res;
        int n=in.size();
        sort(in.begin(),in.end(),[](vector<int>& a,vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        int i=0;
        int start=INT_MAX;
        int end=0;
        while(i<n){
            //int j=i;
            start=in[i][0];
            end=in[i][1];
            while(i<n&&in[i][0]<=end){
                start=min(start,in[i][0]);
                end=max(end,in[i][1]);
                i++;
            }
            res.push_back({start,end});
            //i=j;
        }
        return res;
    }
};
