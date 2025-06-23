#include<bits/stdc++.h>
using namespace std;
using i64=long long;

class Solution {
public:
    i64 maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int len=rides.size();
        sort(rides.begin(),rides.end());
        vector<int> start(len);
        for(int i=0;i<len;i++) start[i]=rides[i][0];
        vector<i64> dp(len+1,0LL);
        for(int i=len-1;i>=0;i--){
            i64 notTake=dp[i+1];
            int lb=lower_bound(start.begin(),start.end(),rides[i][1])-start.begin();
            i64 take=rides[i][1]-rides[i][0]+rides[i][2]+dp[lb];
            dp[i]=max(notTake,take);
        }
        return dp[0];
    }
};