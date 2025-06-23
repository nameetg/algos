#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<int> start(n);
        sort(events.begin(),events.end());
        for(int i=0;i<n;i++) start[i]=events[i][0];
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int K=1;K<=k;K++){
            for(int idx=n-1;idx>=0;idx--){
                int notTake=dp[idx+1][K];
                int ub=upper_bound(start.begin(),start.end(),events[idx][1])-start.begin();
                int take=events[idx][2]+dp[ub][K-1];
                dp[idx][K]=max(take,notTake);
            }
        }
        return dp[0][k];
    }
};