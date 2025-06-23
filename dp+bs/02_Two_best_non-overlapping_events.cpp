#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<int> start(n);
        for(int i=0;i<n;i++) start[i]=events[i][0];
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        for(int k=1;k<3;k++){
            for(int i=n-1;i>=0;i--){
                int notTake=dp[i+1][k];
                int ub=upper_bound(start.begin(),start.end(),events[i][1])-start.begin();
                int take=events[i][2]+dp[ub][k-1];
                dp[i][k]=max(take,notTake);
            }
        }
        return dp[0][2];
    }
};