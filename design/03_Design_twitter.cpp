#include<bits/stdc++.h>
using namespace std;

class Twitter {
public:
    map<int,vector<pair<int,int>>> tweets;
    map<int,unordered_set<int>> followers;
    int timeStamp;
    Twitter() {
        timeStamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        followers[userId].insert(userId);
        for(auto &followee:followers[userId]){
            const auto &t=tweets[followee];
            for(int i=max(0,(int)t.size()-10);i<t.size();i++){
                q.push(t[i]);
                if(q.size()>10) q.pop();
            }
        }
        vector<int> res;
        while(q.size()){
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */