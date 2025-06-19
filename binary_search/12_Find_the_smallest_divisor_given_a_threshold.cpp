#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1,e=1e9;
        while(s<=e){
            int m=(s+e)/2;
            int sum=0;
            for(int x:nums) sum+=((x+m-1)/m);
            if(sum>threshold) s=m+1;
            else e=m-1;
        }
        return s;
    }
};