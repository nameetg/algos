#include<bits/stdc++.h>
using namespace std;

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(n<m) return -1;
    int s=*max_element(arr.begin(),arr.end());
    int e=accumulate(arr.begin(),arr.end(),0);
    while(s<=e){
        int mid=(s+e)/2;
        int studCount=1,pages=0;
        for(int x:arr){
            pages+=x;
            if(pages>mid){
                pages=x;
                studCount++;
            }
        }
        if(studCount>m) s=mid+1;
        else e=mid-1;
    }
    return s;
}