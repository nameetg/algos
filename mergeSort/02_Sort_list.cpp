#include<bits/stdc++.h>
using namespace std;


//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* findMid(ListNode* head){
        if(!head||!head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(left&&right){
            if(left->val<=right->val){
                curr->next=left;
                left=left->next;
            }else{
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
        while(left){
            curr->next=left;
            left=left->next;
            curr=curr->next;
        }
        while(right){
            curr->next=right;
            right=right->next;
            curr=curr->next;
        }
        return dummy->next;
    }
    ListNode* mergeSort(ListNode* head){
        if(!head||!head->next) return head;
        ListNode* mid=findMid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};