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
    int f(int idx, string &s, vector<int> &dp){
        if(idx>=s.length()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int res=s.length()-idx;
        for(int i=idx;i<s.length();i++){
            string t=s.substr(idx,i-idx+1);
            if(T.search(t)) res=min(res,f(i+1,s,dp));
        }
        res=min(res,1+f(idx+1,s,dp));
        return dp[idx]=res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(string &t:dictionary) T.insert(t);
        vector<int> dp(s.length(),-1);
        return f(0,s,dp);
    }
};