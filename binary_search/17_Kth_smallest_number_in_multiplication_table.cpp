#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int s=1,e=m*n;
        while(s<=e){
            int mid=(s+e)/2;
            int sum=0;
            for(int i=1;i<=m;i++)sum+=min(mid/i,n);
            if(sum<k) s=mid+1;
            else e=mid-1;
        }
        return s;
    }
};