#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<pair<int,int>> &a, vector<int> &res, int s, int m, int e){
        vector<pair<int,int>> temp;
        int i=s,j=m+1,count=0;
        while(i<=m&&j<=e){
            if(a[i].first<=a[j].first){
                res[a[i].second]+=count;
                temp.push_back(a[i++]);
            }else{
                count++;
                temp.push_back(a[j++]);
            }
        }
        while(i<=m){
            res[a[i].second]+=count;
            temp.push_back(a[i++]);
        }
        while(j<=e) temp.push_back(a[j++]);
        for(int k=s;k<=e;k++) a[k]=temp[k-s];
    }
    void mergeSort(vector<pair<int,int>> &a, vector<int> &res, int s, int e){
        if(s>=e) return;
        int m=(s+e)/2;
        mergeSort(a,res,s,m);
        mergeSort(a,res,m+1,e);
        merge(a,res,s,m,e);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++) a[i]={nums[i],i};
        mergeSort(a,res,0,n-1);
        return res;
    }
};