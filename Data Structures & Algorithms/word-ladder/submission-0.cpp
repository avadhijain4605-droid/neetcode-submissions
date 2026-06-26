class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        unordered_set<string>vis;
        vis.insert(b);
        queue<pair<int,string>>q;
        q.push({1,b});
        while(!q.empty()){
            string node=q.front().second;
            int step=q.front().first;
            q.pop();
            if(node==e) return step;
            for(int i=0;i<node.length();i++){
                char prev=node[i];
                for(char c='a';c<='z';c++){
                    node[i]=c;
                    if(find(w.begin(),w.end(),node)!=w.end()){
                        if(vis.find(node)==vis.end()) {
                            q.push({step+1,node});
                            vis.insert(node);
                        }
                    }
                }
                node[i]=prev;
            }
        }
        return 0;
    }
};
