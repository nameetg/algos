#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=1,e=arr.size()-2;
        while(s<=e){
            int m=(s+e)/2;
            if(arr[m]>arr[m-1]&&arr[m]>arr[m+1]) return m;
            else if(arr[m]>arr[m-1]) s=m+1;
            else e=m-1;
        }
        return -1;
    }
};