#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        int rowInd=0,colInd=col-1;
        while(rowInd<row&&colInd>=0){
            int ele=matrix[rowInd][colInd];
            if(ele==target) return true;
            else if(ele>target) colInd--;
            else rowInd++;
        }
        return false;
    }
};