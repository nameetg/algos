#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[10];

    TrieNode(){
        for(int i=0;i<10;i++) children[i]=nullptr;
    }
};

class Trie{
    private:
    TrieNode* root;

    public:
    Trie(){
        root=new TrieNode();
    }

    void insert(string s){
        TrieNode* node=root;
        for(char c:s){
            int idx=c-'0';
            if(!node->children[idx]) node->children[idx]=new TrieNode();
            node=node->children[idx];
        }
    }

    int prefLength(string s){
        int res=0;
        TrieNode* node=root;
        for(char c:s){
            int idx=c-'0';
            if(!node->children[idx]) break;
            res++;
            node=node->children[idx];
        }
        return res;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie T;
        for(int e:arr1) T.insert(to_string(e));
        int res=0;
        for(int e:arr2) res=max(res,T.prefLength(to_string(e)));
        return res;
    }
};