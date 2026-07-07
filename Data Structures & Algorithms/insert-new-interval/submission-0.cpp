class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newI) {
     int n=in.size();
    // int end=0;
    vector<vector<int>>res;
     int i=0;
     while(i<n){
        if(in[i][1]<newI[0]){
            res.push_back(in[i]);
            i++;
        }
        else break;
    }
    int end=newI[1];
    int start=newI[0];
    while(i<n&&in[i][0]<=end){
        start=min(start,in[i][0]);
        end=max(end,in[i][1]);
        i++;
    }
    res.push_back({start,end});
    while(i<n){
        res.push_back(in[i]);
        i++;
    }
    return res;
    }
};
