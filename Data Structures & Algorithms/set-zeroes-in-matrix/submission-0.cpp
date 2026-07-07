class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_set<int>row;
        unordered_set<int>col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row.find(i)!=row.end()||col.find(j)!=col.end()) mat[i][j]=0;
            }
        }
    }
};
