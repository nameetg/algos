#include<bits/stdc++.h>
using namespace std;
using i64=long long;

class Solution {
public:
    int dfs(int idx, vector<vector<int>> &b, vector<int> &v){
        v[idx]=1;
        int bombs=1;
        for(int i=0;i<b.size();i++){
            if(!v[i]){
                i64 x=b[idx][0]-b[i][0];
                i64 y=b[idx][1]-b[i][1];
                i64 r=b[idx][2];
                if(x*x+y*y<=r*r) bombs+=dfs(i,b,v);
            }
        }
        return bombs;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        int res=0;
        for(int i=0;i<n;i++){
            vector<int> v(n,0);
            res=max(res,dfs(i,bombs,v));
        }
        return res;
    }
};