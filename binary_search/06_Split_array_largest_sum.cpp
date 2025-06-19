#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int s=*max_element(nums.begin(),nums.end());
        int e=accumulate(nums.begin(),nums.end(),0);
        while(s<=e){
            int m=(s+e)/2;
            int p=1,sum=0;
            for(int &e:nums){
                sum+=e;
                if(sum>m){
                    p++;
                    sum=e;
                }
            }
            if(p>k) s=m+1;
            else e=m-1;
        }
        return s;
    }
};