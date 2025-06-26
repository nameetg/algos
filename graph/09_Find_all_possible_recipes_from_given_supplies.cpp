#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,bool> canCook;
        map<string,int> recIdx;
        for(int i=0;i<recipes.size();i++) recIdx[recipes[i]]=i;
        for(auto& s:supplies) canCook[s]=true;

        function<bool(string)> dfs=[&](string recipe)->bool{
            if(canCook.count(recipe)) return canCook[recipe];
            if(!recIdx.count(recipe)) return false;
            canCook[recipe]=false;
            for(auto& s:ingredients[recIdx[recipe]]){
                if(!dfs(s)) return false;
            }
            return canCook[recipe]=true;
        };

        vector<string> res;
        for(int i=0;i<recipes.size();i++){
            if(dfs(recipes[i])) res.push_back(recipes[i]);
        }
        return res;
    }
};