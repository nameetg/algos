#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,res=1e9;
        while(s<=e){
            int m=(s+e)/2;
            if(nums[s]==nums[m]&&nums[m]==nums[e]){
                res=min(res,nums[s]);
                s++,e--;
            }else if(nums[s]<=nums[m]){
                res=min(res,nums[s]);
                s=m+1;
            }else{
                res=min(res,nums[m]);
                e=m-1;
            }
        }
        return res;
    }
};