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



class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]) node->children[idx]=new TrieNode();
            node=node->children[idx];
        }
        node->isEnd=true;
    }
    
    bool f(int idx, string &s, TrieNode* node){
        if(idx>=s.length()) return node->isEnd;
        bool res=false;
        if(s[idx]!='.'){
            int i=s[idx]-'a';
            if(!node->children[i]) return false;
            res|=f(idx+1,s,node->children[i]);
        }else{
            for(char c='a';c<='z';c++){
                int i=c-'a';
                if(node->children[i]) res|=f(idx+1,s,node->children[i]);
            }
        }
        return res;
    }


    bool search(string word) {
        return f(0,word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */