#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n,0);
        for(auto &e:edges) inDegree[e[1]]++;
        int x=-1;
        for(int i=0;i<n;i++) {
            if(!inDegree[i]){
                if(x!=-1) return -1;
                x=i;
            }
        }
        return x;
    }
};