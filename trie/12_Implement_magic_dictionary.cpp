#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode():isEnd(false){
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
};


class MagicDictionary {
    private:
    TrieNode* root;
public:
    MagicDictionary() {
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
    void buildDict(vector<string> dictionary) {
        for(string &s:dictionary) insert(s);
    }

    bool f(int idx, string &s, TrieNode* node, bool change){
        if(idx>=s.length()) return node->isEnd&&!change;
        int i=s[idx]-'a';
        bool res=false;
        for(int j=0;j<26;j++){
            if(node->children[j]){
                if(i==j) res|=f(idx+1,s,node->children[i],change);
                else if(change) res|=f(idx+1,s,node->children[j],!change);
            }
        }
        return res;
    }
    
    bool search(string searchWord) {
        return f(0,searchWord,root,true);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */