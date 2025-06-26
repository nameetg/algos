#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        map<int,vector<int>> red;
        map<int,vector<int>> blue;
        for(auto &e:redEdges) red[e[0]].push_back(e[1]);
        for(auto &e:blueEdges) blue[e[0]].push_back(e[1]);
        vector<int> res(n,-1);
        queue<tuple<int,int,int>> q;
        map<pair<int,int>,int> v;
        q.push({0,0,-1});
        
        while(q.size()){
            int node=get<0>(q.front());
            int len=get<1>(q.front());
            int color=get<2>(q.front());
            q.pop();
            if(res[node]==-1) res[node]=len;
            // 0->red 1->blue
            if(color!=1){
                for(int e:blue[node]){
                    if(!v.count({e,1})) {
                        q.push({e,len+1,1});
                        v[{e,1}]++;
                    }
                }
            }
            if(color!=0){
                for(int e:red[node]){
                    if(!v.count({e,0})) {
                        q.push({e,len+1,0});
                        v[{e,0}]++;
                    }
                }
            }
        }
        return res;
    }
};