class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mpp;
        for(auto it:tasks){
            mpp[it]++;
        }
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        int sz=max((int)tasks.size(),pq.top().first*(n+1));
        vector<char>ans(sz,'*');
        queue<pair<int,int>>q;
        for(int i=0;i<sz;i++){
            while(!q.empty()&&q.front().second<i){
                char c=q.front().first;
                pq.push({mpp[c],c});
                q.pop();
            }
            if(pq.empty())continue;
            ans[i]=pq.top().second;
            pq.pop();
            mpp[ans[i]]--;
            if(mpp[ans[i]]==0) mpp.erase(ans[i]-'a');
            if(mpp[ans[i]]>0)q.push({ans[i],i+n});
        }
        int r=sz-1;
        while(r>=0&&ans[r]=='*')r--;
        return r+1;
    }
};
