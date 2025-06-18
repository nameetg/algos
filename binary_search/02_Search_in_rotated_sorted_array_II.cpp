#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        while(s<=e){
            int m=(s+e)/2;
            if(nums[m]==target) return true;
            if(nums[s]==nums[m]&&nums[m]==nums[e]) s++,e--;
            else if(nums[s]<=nums[m]){
                if(target>=nums[s]&&target<=nums[m]) e=m-1;
                else s=m+1;
            }else{
                if(target<=nums[e]&&nums[m]<=target) s=m+1;
                else e=m-1;
            }
        }
        return false;
    }
};