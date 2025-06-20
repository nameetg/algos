#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right){
        if(!left) return right;
        if(!right) return left;
        if(left->val<=right->val){
            left->next=merge(left->next,right);
            return left;
        }
        right->next=merge(left,right->next);
        return right;
    }
    ListNode* mergeLists(vector<ListNode*> &a, int s, int e){
        if(s==e) return a[s];
        int m=(s+e)/2;
        ListNode* left=mergeLists(a,s,m);
        ListNode* right=mergeLists(a,m+1,e);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(!n) return NULL;
        return mergeLists(lists,0,n-1);
    }
};