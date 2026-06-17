class Twitter {
public:
    int timestamp;
    unordered_map<int,unordered_set<int>>followings;
    unordered_map<int,vector<pair<int,int>>>posts;
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timestamp,tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto it:posts[userId]){
            pq.push(it);
        }
        for(auto i:followings[userId]){
            for(auto& it:posts[i]){
                pq.push(it);
            }
        }
        vector<int>ans;
        int n=min((int)pq.size(),10);
        while(n--){
            auto i=pq.top();
            pq.pop();
            ans.push_back(i.second);
        }
        //reverse(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it=find(followings[followerId].begin(),followings[followerId].end(),followeeId);
        if(it==followings[followerId].end()) return;
        else followings[followerId].erase(it);
    }
};
