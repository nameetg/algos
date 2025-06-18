#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key,val,freq;
    Node* next;
    Node* prev;

    Node(int key, int val): key(key),val(val),freq(1), next(nullptr), prev(nullptr){}
};

class List{
    public:
    int size;
    Node* head;
    Node* tail;

    List(): size(0){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void insert(Node* node){
        Node* next=head->next;
        node->next=next;
        head->next=node;
        node->prev=head;
        next->prev=node;
        size++;
    }

    void remove(Node* node){
        Node* next=node->next;
        Node* prev=node->prev;
        next->prev=prev;
        prev->next=next;
        size--;
    }
};

class LFUCache {
public:
    int minFreq,currSize,cap;
    map<int,Node*> keyNode;
    map<int,List*> freqMap;
    LFUCache(int capacity) {
        minFreq=0;
        currSize=0;
        cap=capacity;
    }

    void update(Node* node){
        keyNode.erase(node->key);
        freqMap[node->freq]->remove(node);
        if(node->freq==minFreq&&freqMap[node->freq]->size==0) minFreq++;
        node->freq++;
        List* newList=new List();
        if(freqMap.count(node->freq)) newList=freqMap[node->freq];
        newList->insert(node);
        freqMap[node->freq]=newList;
        keyNode[node->key]=node;
    }
    
    int get(int key) {
        if(keyNode.count(key)){
            Node* node=keyNode[key];
            update(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyNode.count(key)){
            Node* node=keyNode[key];
            node->val=value;
            update(node);
        }else{
            if(currSize==cap){
                List* list=freqMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqMap[minFreq]->remove(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq=1;
            List* newList=new List();
            if(freqMap.count(minFreq)) newList=freqMap[minFreq];
            Node* node=new Node(key,value);
            newList->insert(node);
            keyNode[key]=node;
            freqMap[minFreq]=newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */