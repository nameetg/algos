#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[52];
    bool isEnd;

    TrieNode(): isEnd(false){
        for(int i=0;i<52;i++) children[i]=nullptr;
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
            if(c>='A'&&c<='Z'){
                int idx=c-'A';
                if(!node->children[idx]) node->children[idx]=new TrieNode();
                node=node->children[idx];
            }
            else{
                int idx=26+c-'a';
                if(!node->children[idx]) node->children[idx]=new TrieNode();
                node=node->children[idx];
            }
        }
        node->isEnd=true;
    }

    bool check(string &word){
        TrieNode* node=root;
        for(char c:word){
            if(c>='A'&&c<='Z'){
                int idx=c-'A';
                if(!node->children[idx]) return false;
                node=node->children[idx];
            }else{
                int idx=26+c-'a';
                if(node->children[idx]) node=node->children[idx];
            }
        }
        return node->isEnd;
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie T;
        T.insert(pattern);
        vector<bool> res(queries.size());
        for(int i=0;i<queries.size();i++) res[i]=T.check(queries[i]);
        return res;
    }
};