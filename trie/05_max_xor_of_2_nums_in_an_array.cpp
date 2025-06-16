#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[2];

    TrieNode(){
        children[0]=children[1]=nullptr;
    }
};

class Trie{
    private:
    TrieNode* root;

    public:

    Trie(){
        root=new TrieNode();
    }

    void insert(int num){
        TrieNode* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->children[bit]) node->children[bit]=new TrieNode();
            node=node->children[bit];
        }
    }

    int max(int num){
        int res=0;
        TrieNode* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->children[1-bit]){
                res=res|(1<<i);
                node=node->children[1-bit];
            }
            else node=node->children[bit];
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res=0;
        Trie T;
        for(int e:nums) T.insert(e);
        for(int e:nums) res=max(res,T.max(e));
        return res;
    }
};