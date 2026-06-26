class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==1) return true;
            if(vis[it]==0){
                if(dfs(it,adj,vis)) return true;
            }
        }
        vis[node]=2;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int>in(n,0);
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(auto it:p){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            in[v]++;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis)) return {};
            }
        }
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(in[i]==0){
            st.push(i);
            ans.push_back(i);
            }
        }
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0) {
                    st.push(it);
                    ans.push_back(it);
                }

            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
