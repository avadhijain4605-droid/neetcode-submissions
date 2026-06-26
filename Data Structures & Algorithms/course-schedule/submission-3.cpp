
class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        for(auto v:adj[node]){
            if(vis[v]==1) return true;
            else if(vis[v]==0){
                if(dfs(v,adj,vis)) return true;
            }
        }
        vis[node]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        if(p.size()==0) return true;
        vector<vector<int>>adj(n);
        for(auto it:p){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis)) return false ;
            }
        }
        return true;
    }
};
