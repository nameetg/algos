#include <bits/stdc++.h> 
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    int countEnd,countPrefix;

    TrieNode(): countEnd(0), countPrefix(0){
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
};



class Trie{

    public:
    TrieNode* root;
    Trie(){
        // Write your code here.
        root=new TrieNode();
    }

    void insert(string &word){
        // Write your code here.
        TrieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]) node->children[idx]=new TrieNode();
            node=node->children[idx];
            node->countPrefix++;
        }
        node->countEnd++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        TrieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]) return 0;
            node=node->children[idx];
        }
        return node->countEnd;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        TrieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]) return 0;
            node=node->children[idx];
        }
        return node->countPrefix;
    }

    void erase(string &word){
        // Write your code here.
        if(!countWordsEqualTo(word)) return;
        TrieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            TrieNode* child=node->children[idx];
            child->countPrefix--;
            node=child;
        }
        node->countEnd--;
    }
};
