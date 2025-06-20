#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int> &a, int s, int m, int e){
        vector<int> left(a.begin()+s,a.begin()+m+1);
        vector<int> right(a.begin()+m+1,a.begin()+e+1);
        int i=0,j=0,k=s;
        while(i<left.size()&&j<right.size()){
            if(left[i]<=right[j]) a[k++]=left[i++];
            else a[k++]=right[j++];
        }
        while(i<left.size()) a[k++]=left[i++];
        while(j<right.size()) a[k++]=right[j++];
    }
    void mergeSort(vector<int> &a, int s, int e){
        if(s<e){
            int m=(s+e)/2;
            mergeSort(a,s,m);
            mergeSort(a,m+1,e);
            merge(a,s,m,e);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};