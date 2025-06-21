#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(vector<int>& a, int s, int m, int e){
        vector<int> left(a.begin()+s,a.begin()+m+1);
        vector<int> right(a.begin()+m+1,a.begin()+e+1);
        int i=0,j=0,k=s,res=0;
        while(i<left.size()&&j<right.size()){
            if(left[i]<=right[j]) a[k++]=left[i++];
            else a[k++]=right[j++];
        }
        while(i<left.size()) a[k++]=left[i++];
        while(j<right.size()) a[k++]=right[j++];
        i=0,j=0;
        while(i<left.size()){
            while(j<right.size()&&left[i]>2LL*right[j]) j++;
            res+=j;
            i++;
        }
        return res;
    }

    int mergeSort(vector<int> &a, int s, int e){
        int res=0;
        if(s<e){
            int m=(s+e)/2;
            res+=mergeSort(a,s,m);
            res+=mergeSort(a,m+1,e);
            res+=merge(a,s,m,e);
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};