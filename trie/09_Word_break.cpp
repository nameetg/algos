#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(): isEnd(false){
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
};

class Trie{
    private:
    TrieNode* root;

    public:

    Trie(){
        root=new TrieNode();
    }

    void insert(string &word){
        TrieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]) node->children[idx]=new TrieNode();
            node=node->children[idx];
        }
        node->isEnd=true;
    }

    bool search(string &word){
        TrieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]) return false;
            node=node->children[idx];
        }
        return node->isEnd;
    }
};

class Solution {
public:
    Trie T;
    bool f(int idx, string &s, vector<int> &dp){
        if(idx>=s.length()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.length();i++){
            string t=s.substr(idx,i-idx+1);
            if(T.search(t)){
                if(f(i+1,s,dp)) return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string &t:wordDict) T.insert(t);
        vector<int> dp(s.length(),-1);
        return f(0,s,dp)==1;
    }
};