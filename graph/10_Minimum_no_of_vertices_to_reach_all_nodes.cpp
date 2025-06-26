#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        vector<int> res;
        for(auto& e:edges) visited[e[1]]++;
        for(int i=0;i<n;i++) if(!visited[i]) res.push_back(i);
        return res;
    }
};