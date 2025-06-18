#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key,val;
    Node* prev;
    Node* next;

    Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    int cap;
    map<int,Node*> m;
    Node* head;
    Node* tail;
    LRUCache(int capacity):cap(capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void insert(Node* node){
        Node* next=head->next;
        head->next=node;
        node->next=next;
        node->prev=head;
        next->prev=node;
        m[node->key]=node;
    }
    
    void remove(Node* node){
        Node* next=node->next;
        Node* prev=node->prev;
        prev->next=next;
        next->prev=prev;
        m.erase(node->key);
    }
    int get(int key) {
        if(m.count(key)){
            Node* node=m[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            Node* node=m[key];
            node->val=value;
            remove(node);
            insert(node);
        }else{
            Node* newNode=new Node(key,value);
            if(m.size()==cap) remove(tail->prev);
            insert(newNode);
            m[key]=newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */