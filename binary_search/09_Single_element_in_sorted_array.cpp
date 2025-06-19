#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int s=1,e=n-2;
        while(s<=e){
            int m=(s+e)/2;
            if(nums[m]!=nums[m-1]&&nums[m]!=nums[m+1]) return nums[m];
            else if(m&1){
                if(nums[m]==nums[m+1]) e=m-1;
                else s=m+1;
            }else{
                if(nums[m]==nums[m+1]) s=m+1;
                else e=m-1;
            }
        }
        return -1;
    }
};