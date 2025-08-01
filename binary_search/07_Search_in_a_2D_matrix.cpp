#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int s=0,e=n*m-1;
        while(s<=e){
            int mid=(s+e)/2;
            int ele=matrix[mid/m][mid%m];
            if(ele==target) return true;
            else if(ele>target) e=mid-1;
            else s=mid+1;
        }
        return false;
    }
};