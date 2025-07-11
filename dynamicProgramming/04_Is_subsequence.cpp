#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length(),m=t.length();
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++) dp[i][0]=0;
        for(int i=0;i<m+1;i++) dp[0][i]=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m]==n;
    }
};