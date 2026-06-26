class Solution {
public:
    bool dfs(int node,int par,vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(it==par)continue;
            if(vis[it]==1) return true;
            else{
                if(dfs(it,node,adj,vis)) return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        vector<int>in(n,0);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            in[v]++;
        }
        //for(int i=0;i<n;i++)cout<<in[i]<<endl;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                if(dfs(i,-1,adj,vis)) {
                    cout<<i<<endl;
                    return false;
                }
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};
