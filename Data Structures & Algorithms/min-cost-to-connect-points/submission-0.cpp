class DSU{
    public:
    vector<int>par;
    vector<int>rank;
    DSU(int n){
        rank.assign(n,0);
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
    }
    int findP(int u){
        if(par[u]==u) return par[u];
        return par[u]=findP(par[u]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findP(u);
        int ulp_v=findP(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]>rank[ulp_v]){
            par[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]==rank[ulp_v]){
            par[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
        else{
            par[ulp_u]=ulp_v;
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=p[i][0];
                int y1=p[i][1];
                int x2=p[j][0];
                int y2=p[j][1];
                int dis=abs(x1-x2)+abs(y1-y2);
                edges.push_back(vector<int>{i,j,dis});
            }
        }
        sort(edges.begin(),edges.end(),[](const vector<int>& a, const vector<int>& b){
            return a[2]<b[2];
        });
        DSU ds(n);
        int total=0;
        for(auto e:edges){
            if(ds.findP(e[0])==ds.findP(e[1]))continue;
            ds.unionByRank(e[0],e[1]);
            total+=e[2];
        }
        return total;
    }
};