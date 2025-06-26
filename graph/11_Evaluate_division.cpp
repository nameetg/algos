#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<string,vector<pair<string,double>>> g;
    double dfs(string &a, string &b, set<string> &vis){
        if(a==b) return 1.0;
        vis.insert(a);
        for(auto &e:g[a]){
            if(!vis.count(e.first)){
                double val=dfs(e.first,b,vis);
                if(val!=-1) return val*e.second;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<values.size();i++) {
            g[equations[i][0]].push_back({equations[i][1],values[i]});
            g[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double> res(queries.size(),-1.0);
        for(int i=0;i<queries.size();i++){
            if(!g.count(queries[i][0])||!g.count(queries[i][1])) continue;
            set<string> vis;
            res[i]=dfs(queries[i][0],queries[i][1],vis);
        }
        return res;
    }
};