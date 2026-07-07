class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& tri, vector<int>& target) {
       sort(tri.begin(),tri.end());
       int n=tri.size();
       vector<int>pre={0,0,0};
       for(int i=0;i<n;i++){
        if(tri[i][0]>target[0]||tri[i][1]>target[1]||tri[i][2]>target[2]) continue;
        pre[0]=max(pre[0],tri[i][0]);
        pre[1]=max(pre[1],tri[i][1]);
        pre[2]=max(pre[2],tri[i][2]);
        if(pre[0]==target[0]&&pre[1]==target[1]&&pre[2]==target[2]) return true;
       } 
       return false;
    }
};
