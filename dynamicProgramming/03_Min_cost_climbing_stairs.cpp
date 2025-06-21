#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int last=cost[0],curr=cost[1];
        for(int i=2;i<cost.size();i++){
            int temp=cost[i]+min(last,curr);
            last=curr;
            curr=temp;
        }
        return min(curr,last);
    }
};