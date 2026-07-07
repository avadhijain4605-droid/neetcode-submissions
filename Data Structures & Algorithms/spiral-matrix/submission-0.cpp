class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int l=(min(m,n)+1)/2;
        vector<int>ans;
        for(int k=0;k<l;k++){
            for(int i=k;i<n-k;i++){
                ans.push_back(mat[k][i]);
            }
            for(int i=k+1;i<m-k;i++){
                ans.push_back(mat[i][n-1-k]);
            }
            if(k<m-k-1)
            for(int i=n-2-k;i>=k;i--){
                ans.push_back(mat[m-1-k][i]);
            }
            if(k<n-k-1)
            for(int i=m-2-k;i>k;i--){
                ans.push_back(mat[i][k]);
            }
        }
        return ans;
    }
};
