#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<tuple<int,int,int>> a(n);
        for(int i=0;i<n;i++) a[i]={startTime[i],endTime[i],profit[i]};
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++) startTime[i]=get<0>(a[i]), endTime[i]=get<1>(a[i]),profit[i]=get<2>(a[i]);
        int dp[n+1];
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int nt=dp[i+1];
            int lb=lower_bound(startTime.begin(),startTime.end(),endTime[i])-startTime.begin();
            int t=profit[i]+dp[lb];
            dp[i]=max(t,nt);
        }
        return dp[0];
    }
};