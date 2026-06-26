class DSU{
public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findP(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findP(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findP(u);
        int ulp_v = findP(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU ds(n);
        vector<int>ans(2,-1);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            if(ds.findP(u)==ds.findP(v)){
                ans[0]=u;
                ans[1]=v;
                return ans;
            }
            else ds.unionByRank(u,v);
        }
        return ans;
    }
};
