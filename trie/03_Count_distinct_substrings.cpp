#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    Trie* children[26];

    Trie(){
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Trie* root=new Trie();
    int res=0;

    for(int i=0;i<s.length();i++){
        Trie* node=root;
        for(int j=i;j<s.length();j++){
            int idx=s[j]-'a';
            if(!node->children[idx]){
                res++;
                node->children[idx]=new Trie();
            }
            node=node->children[idx];
        }
    }
    return res+1;
}