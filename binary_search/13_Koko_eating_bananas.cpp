#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=1e9;
        while(s<=e){
            int m=(s+e)/2;
            i64 need=0;
            for(int x:piles) need+=(x+m-1)/m;
            if(need>h) s=m+1;
            else e=m-1;
        }
        return s;
    }
};