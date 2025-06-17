#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    int freq;

    TrieNode(): freq(0){
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
};

class MapSum {
public:
    map<string,int> m;
    TrieNode* root;
    MapSum() {
        root=new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* node=root;
        int toAdd=val-m[key];
        for(char c:key){
            int idx=c-'a';
            if(!node->children[idx]) node->children[idx]=new TrieNode();
            node=node->children[idx];
            node->freq+=toAdd;
        }
        m[key]=val;
    }
    
    int sum(string prefix) {
        TrieNode* node=root;
        int res=0;
        for(char c:prefix){
            int idx=c-'a';
            if(!node->children[idx]) return 0;
            node=node->children[idx];
            res=node->freq;
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */