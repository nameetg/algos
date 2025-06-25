#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n+1,-1e9);
        dp[n]=0;
        for(int idx=n-1;idx>=0;idx--){
            int sum=0,best=-1e9;
            for(int i=idx;i<min(n,idx+3);i++){
                sum+=stoneValue[i];
                best=max(best,sum-dp[i+1]);
            }
            dp[idx]=best;
        }
        if(!dp[0]) return "Tie";
        else if(dp[0]>0) return "Alice";
        return "Bob";
    }
};