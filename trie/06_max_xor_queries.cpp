#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[2];

    TrieNode(){
        children[1]=children[0]=nullptr;
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
        TrieNode* node=root;
        int res=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->children[1-bit]){
                res=res|(1<<i);
                node=node->children[1-bit];
            }
            else if(node->children[bit]) node=node->children[bit];
            else return -1;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<tuple<int,int,int>> q;
        for(int i=0;i<queries.size();i++) q.emplace_back(queries[i][1],queries[i][0],i);
        sort(q.begin(),q.end());
        Trie T;
        vector<int> res(queries.size(),-1);
        int idx=0;
        for(auto &[mi,xi,i]:q){
            while(idx<nums.size()&&nums[idx]<=mi){
                T.insert(nums[idx]);
                idx++;
            }
            if(!idx) res[i]=-1;
            else res[i]=T.max(xi);
        }
        return res;
    }
};