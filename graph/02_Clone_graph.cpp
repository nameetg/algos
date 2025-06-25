#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        map<Node*,Node*> v;
        queue<Node*> q;
        q.push(node);
        v[node]=new Node(node->val);
        while(q.size()){
            Node* front=q.front();
            q.pop();
            for(auto nei:front->neighbors){
                if(!v.count(nei)){
                    q.push(nei);
                    v[nei]=new Node(nei->val);
                }
                v[front]->neighbors.push_back(v[nei]);
            }
        }
        return v[node];
    }
};